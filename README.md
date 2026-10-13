# Selective Forwarding Attacks in IoT Networks

A simulation-based study demonstrating how selective forwarding attacks silently degrade IoT network reliability while preserving routing stability.

## Project Overview

- Simulated IoT networks using Contiki OS and Cooja
- Implemented a malicious node that selectively drops packets
- Observed packet loss behavior while maintaining stable routing
- Analyzed the impact on retransmissions, routing efficiency, and energy consumption

## 💻 Technical Stack & Environment
* **Language:** C (Low-level firmware optimization)
* **Operating System:** Contiki OS (2.7 / 3.0 / NG)
* **Simulation Framework:** Cooja Network Simulator
* **Protocol Target:** RPL (Routing Protocol for Low-Power and Lossy Networks)
* **Traffic Analysis:** PCAP Capture, Packet Delivery Metrics, ETX (Expected Transmission Count) Analysis

## 🎯 Key Architectural Components
1. **Malicious Node Implementation (`/malicious-nodes`):** Contains custom firmware modifications written in C to reproduce covert packet-dropping behavior (such as silently dropping every 3rd packet).
2. **Network Resilience & Mobility:** Evaluation framework distinguishing between static and dynamic behaviors to analyze network stability under node physical movement.
3. **Detection Baseline:** Utilizes routing topology changes, Radio Duty Cycle spikes, and drastic Estimated Transmission Count (ETX) updates to isolate and identify misbehaving nodes.

## 📊 Experimental Metrics & Results
Through multi-node network graphing and simulation control parameters inside Cooja, the project captures distinct operational anomalies:
* **Telemetry Data:** Successfully traced malicious drops inside the Cooja Mote Output timeline pane matching dropped sequence counts.
* **Power Profiling:** Traced abnormal Instantaneous Power Consumption indicators (anomalies spiking during path recalculation or active attacks).
* **Topology Shifts:** Monitored real-time sensor connections showing how surrounding child nodes proactively swap parent routes away from misbehaving node clusters.

## Medium Articles

📖 **Part 1 – Observing a Selective Forwarding Attack**  
👉 https://medium.com/@shreyagajjar2024/when-an-iot-network-looks-healthy-but-isnt-observing-a-selective-forwarding-attack-a1c1c4882fb0

## Repository Structure

- `images/` – Simulation screenshots  
- `simulations/` – Cooja setups  
- `malicious-node/` – Forwarding logic  
- `data/` – Metrics  
- `docs/` – Articles  

## Future Work

- Code-level attack implementation  
- Power consumption analysis  
- Static vs dynamic network comparison  

## Author

**Shreya Gajjar**  
Cybersecurity | IoT Security | Network Security
