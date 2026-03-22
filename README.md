# Selective Forwarding Attacks in IoT Networks

A simulation-based study demonstrating how selective forwarding attacks silently degrade IoT network reliability while preserving routing stability.

## Key Insight

An IoT network can appear fully functional while silently losing data.  
Selective forwarding attacks exploit this by dropping packets without disrupting routing, making detection difficult using traditional methods.

## Simulation Preview

### Network Topology (Normal Operation)
![Topology](images/1_Connected%20IoT%20Network%20with%20Established%20routing%20paths.png)

### Selective Forwarding Behavior (Packet Drop Evidence)
![Selective Drop](images/2_Selective%20forwarding%20dropping.png)

### Compromised Node in Network
![Compromised Node](images/3_network%20Highlights%20Compromised%20Node.png)

### Sink Initialization and Routing Activity
![Sink Init](images/Successful%20Sink%20Initialization.png)

## Project Overview

- Simulated IoT networks using Contiki OS and Cooja
- Implemented a malicious node that selectively drops packets
- Observed packet loss behavior while maintaining stable routing
- Analyzed the impact on retransmissions, routing efficiency, and energy consumption

## Tools & Technologies

- Contiki OS
- Cooja Simulator
- RPL Routing Protocol
- UDP-based traffic generation
- IoT sensor nodes

## Medium Articles

This work is explained in detail in a Medium article series:

📖 **Part 1 – Observing a Selective Forwarding Attack**  
👉 https://medium.com/@shreyagajjar2024/when-an-iot-network-looks-healthy-but-isnt-observing-a-selective-forwarding-attack-a1c1c4882fb0

## Repository Structure

- `simulations/` – Cooja simulation setups  
- `malicious-node/` – Malicious forwarding logic  
- `data/` – Metrics (packet loss, power, sensor data)  
- `images/` – Simulation screenshots  
- `docs/` – Article drafts and documentation  

## Future Work

- Code-level analysis of malicious forwarding logic  
- Power consumption impact under attack  
- Static vs dynamic node comparison  
- Lightweight detection mechanisms for IoT networks  

## Author

**Shreya Gajjar**  
Cybersecurity | IoT Security | Network Security
