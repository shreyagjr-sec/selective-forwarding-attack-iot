# Analyzing Selective Forwarding Attacks in RPL

**Contiki OS · Cooja Simulator · C · IPv6/RPL · IoT Security**

An IoT security project by **Shreya Gajjar**, investigating selective packet dropping in a simulated RPL network. I set up the simulation environment, modified node code, ran normal-network, mobility, and malicious-node scenarios, and documented the behavior through Cooja and sensor data collection views.

This repository presents my minor project from my 2024 undergraduate internship/project report. It includes the existing public C sources and the complete project chapter, with its ten original figures in a separate gallery.

## My contribution

- Set up Contiki OS and Cooja for an RPL-based network with a root/sink and sensor nodes.
- Modified node behavior for an experiment configured to drop every third packet.
- Examined a normal network and a scenario with one mobile node.
- Collected screenshots of topology, node information, sensor readings, power consumption, and packet-drop output.
- Documented the experimental objectives, setup, and observations.

## Experiment at a glance

| Scenario | Purpose | Evidence from the report |
| --- | --- | --- |
| Normal network | Establish baseline network and sensor behavior | Figures 4.1–4.5 |
| One mobile node | Inspect node data and power behavior with mobility | Figures 4.6–4.7 |
| Malicious node | Observe the reported every-third-packet drop experiment | Figures 4.8–4.10 |

The report describes dropping packets 3, 6, 9, and so on at the malicious node. This configured selection rule does **not** establish a one-third loss rate across the whole network; end-to-end loss depends on traffic paths and other network conditions.

**[Read the complete project chapter](docs/project-report.md)** · **[View all ten figures](images/figures.md)**

## Source code and experiment status

| File | What is available |
| --- | --- |
| [`malicious-nodes/honest_node.c`](malicious-nodes/honest_node.c) | Baseline UDP client source using Contiki collection components |
| [`malicious-nodes/udp-malicious-demo.c`](malicious-nodes/udp-malicious-demo.c) | Public demonstration showing the intended packet-selection insertion point; its actual packet-drop logic was intentionally withheld by the author for safety |
| [`docs/project-report.md`](docs/project-report.md) | Full Chapter 4 text, with figure captions and a link to the gallery |
| [`images/figures.md`](images/figures.md) | Single gallery displaying all ten original report figures |
| [`images/report/`](images/report/) | Image assets used by the gallery |

The original experimental work and the current public source snapshot are distinct: **I intentionally withheld the actual malicious packet-selection and drop logic from the public code for safety reasons. The published demo therefore does not execute the every-third-packet drop rule.** Both current sources invoke UDP transmission from `collect_common_send()` and ignore incoming application data in `tcpip_handler()`. They do not by themselves establish an implementation that drops transit packets inside RPL's forwarding path.

The existing C files are preserved. The exact Contiki revision, build files, sink source, saved Cooja configuration, mobility configuration, and raw measurement logs are not included in the current repository. Consequently, this is a documented project with partial source availability rather than a complete reproducible experiment package.

## Methodology and evidence

The project aims to assess packet loss, latency, reliability, and RPL behavior under selective forwarding. The report provides visual evidence of the simulations, data collection views, and a packet-drop event. It does not provide raw logs, repeated-run statistics, or a numerical baseline-versus-attack results table, so no measured performance improvement or network-wide loss percentage is claimed here.

Detection and mitigation were project objectives. A validated detector, tested mitigation implementation, or demonstrated automatic avoidance of malicious nodes is not established by the supplied chapter.

## Reviewing or reproducing the work

1. Read the [project chapter](docs/project-report.md) for the original scenario and screenshots.
2. Review the two C files for the public baseline and demonstration structure.
3. For a future rerun, recover the original Contiki environment, collection dependencies, sink, build configuration, simulation topology, and mobility settings.
4. Restore and verify the original experimental drop implementation, including whether it acts on locally generated traffic or forwarded traffic.
5. Run matched baseline and attack trials, saving packet identifiers, timestamps, routes, and power measurements for a quantitative comparison.

Exact build and run commands are not supplied because the required project configuration and original environment version are not recorded here. No compilation or simulation rerun was performed for this documentation update.

## Related writing

[When an IoT Network Looks Healthy but Isn’t: Observing a Selective Forwarding Attack](https://medium.com/@shreyagajjar2024/when-an-iot-network-looks-healthy-but-isnt-observing-a-selective-forwarding-attack-a1c1c4882fb0)

## Author

**Shreya Gajjar** — Cybersecurity · IoT Security · Network Security

Project ownership and hands-on contributions are stated by the author. Contiki OS, Cooja, and their underlying examples and libraries are third-party components; author credit here refers to the project setup, modifications, experiments, and documentation.
