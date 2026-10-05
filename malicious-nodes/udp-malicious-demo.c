/*
 * udp-malicious-demo.c
 *
 * Sanitized demonstration of a selective forwarding node for an
 * RPL-based IoT network running on Contiki OS.
 *
 * SECURITY NOTE:
 * The operational packet-selection/drop condition used in the research
 * experiment has intentionally been omitted from this public version.
 *
 * This file demonstrates WHERE selective forwarding behavior is introduced
 * and HOW it differs structurally from the honest baseline, without
 * publishing the exact attack implementation.
 *
 * Author: Shreya Gajjar
 * Project: Selective Forwarding Attack Detection in IoT Networks
 */

#include "contiki.h"
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/ip/uip-udp-packet.h"
#include "net/rpl/rpl.h"
#include "dev/serial-line.h"

#if CONTIKI_TARGET_Z1
#include "dev/uart0.h"
#else
#include "dev/uart1.h"
#endif

#include "collect-common.h"
#include "collect-view.h"

#include <stdio.h>

#define UDP_CLIENT_PORT 8775
#define UDP_SERVER_PORT 5688

#define DEBUG DEBUG_PRINT
#include "net/ip/uip-debug.h"

static struct uip_udp_conn *client_conn;
static uip_ipaddr_t server_ipaddr;

PROCESS(udp_client_process, "UDP client process");
AUTOSTART_PROCESSES(&udp_client_process, &collect_common_process);

/*---------------------------------------------------------------------------*/
void
collect_common_net_print(void)
{
  rpl_dag_t *dag;
  uip_ds6_route_t *r;

  dag = rpl_get_any_dag();

  if(dag != NULL && dag->preferred_parent != NULL) {
    PRINTF("Preferred parent: ");
    PRINT6ADDR(rpl_get_parent_ipaddr(dag->preferred_parent));
    PRINTF("\n");
  }

  for(r = uip_ds6_route_head(); r != NULL; r = uip_ds6_route_next(r)) {
    PRINT6ADDR(&r->ipaddr);
  }

  PRINTF("---\n");
}

/*---------------------------------------------------------------------------*/
void
collect_common_set_sink(void)
{
  /* Client node — not a sink */
}

/*---------------------------------------------------------------------------*/
static void
tcpip_handler(void)
{
  if(uip_newdata()) {
    /* Ignore incoming data */
  }
}

/*---------------------------------------------------------------------------*/
/*
 * SELECTIVE FORWARDING DEMONSTRATION
 *
 * Honest behavior:
 *
 *     packet received/generated
 *              |
 *              v
 *           forward
 *
 * Experimental malicious behavior:
 *
 *     packet received/generated
 *              |
 *              v
 *       [selection logic]
 *          /       \
 *      forward     drop
 *
 * The exact packet-selection/drop condition used during the experiment
 * is intentionally NOT included in this public repository.
 *
 * In the private experimental implementation, selected packets return
 * before reaching uip_udp_packet_sendto().
 */
/*---------------------------------------------------------------------------*/
void
collect_common_send(void)
{
  static uint8_t seqno;

  struct {
    uint8_t seqno;
    uint8_t for_alignment;
    struct collect_view_data_msg msg;
  } msg;

  seqno++;
  msg.seqno = seqno;

  /*
   * ---------------------------------------------------------------
   * SELECTIVE FORWARDING ATTACK POINT
   * ---------------------------------------------------------------
   *
   * Private experimental implementation:
   *
   *     if(<packet-selection condition>) {
   *         <record packet as intentionally dropped>;
   *         return;
   *     }
   *
   * The operational condition is omitted from the public version.
   *
   * Returning here prevents the selected packet from reaching the
   * UDP transmission function below, thereby simulating selective
   * forwarding behavior.
   * ---------------------------------------------------------------
   */

  /*
   * Packets not selected for dropping continue through the normal
   * forwarding path.
   */
  uip_udp_packet_sendto(client_conn,
                        &msg,
                        sizeof(msg),
                        &server_ipaddr,
                        UIP_HTONS(UDP_SERVER_PORT));
}

/*---------------------------------------------------------------------------*/
void
collect_common_net_init(void)
{
#if CONTIKI_TARGET_Z1
  uart0_set_input(serial_line_input_byte);
#else
  uart1_set_input(serial_line_input_byte);
#endif

  serial_line_init();
}

/*---------------------------------------------------------------------------*/
static void
print_local_addresses(void)
{
  int i;
  uint8_t state;

  PRINTF("Client IPv6 addresses: ");

  for(i = 0; i < UIP_DS6_ADDR_NB; i++) {
    state = uip_ds6_if.addr_list[i].state;

    if(uip_ds6_if.addr_list[i].isused &&
       (state == ADDR_TENTATIVE || state == ADDR_PREFERRED)) {

      PRINT6ADDR(&uip_ds6_if.addr_list[i].ipaddr);
      PRINTF("\n");

      if(state == ADDR_TENTATIVE) {
        uip_ds6_if.addr_list[i].state = ADDR_PREFERRED;
      }
    }
  }
}

/*---------------------------------------------------------------------------*/
static void
set_global_address(void)
{
  uip_ipaddr_t ipaddr;

  uip_ip6addr(&ipaddr,
              0xaaaa, 0, 0, 0,
              0, 0, 0, 0);

  uip_ds6_set_addr_iid(&ipaddr, &uip_lladdr);
  uip_ds6_addr_add(&ipaddr, 0, ADDR_AUTOCONF);

  /* Sink/server address */
  uip_ip6addr(&server_ipaddr,
              0xaaaa, 0, 0, 0,
              0, 0, 0, 1);
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(udp_client_process, ev, data)
{
  PROCESS_BEGIN();

  PROCESS_PAUSE();

  set_global_address();

  PRINTF("Selective forwarding demonstration node started\n");

  print_local_addresses();

  client_conn = udp_new(NULL,
                        UIP_HTONS(UDP_SERVER_PORT),
                        NULL);

  udp_bind(client_conn,
           UIP_HTONS(UDP_CLIENT_PORT));

  PRINTF("Created connection with server ");
  PRINT6ADDR(&client_conn->ripaddr);

  PRINTF(" local/remote port %u/%u\n",
         UIP_HTONS(client_conn->lport),
         UIP_HTONS(client_conn->rport));

  while(1) {
    PROCESS_YIELD();

    if(ev == tcpip_event) {
      tcpip_handler();
    }
  }

  PROCESS_END();
}

/*---------------------------------------------------------------------------*/
