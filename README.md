# Selective Forwarding Attacks in IoT Networks

This repository contains experimental work analyzing selective forwarding attacks in IoT networks using **Contiki OS** and the **Cooja simulator**.

Selective forwarding attacks are particularly difficult to detect because malicious nodes continue to participate in routing while silently dropping selected packets. This project demonstrates how such attacks can degrade network reliability without triggering obvious failures.

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

## Medium Article

This work is explained in detail in a Medium article series.

**Part 1 – Observing a Selective Forwarding Attack**  
Link: https://medium.com/@shreyagajjar2024/when-an-iot-network-looks-healthy-but-isnt-observing-a-selective-forwarding-attack-a1c1c4882fb0

## Repository Structure

- `simulations/` – Cooja simulation setups
- `malicious-node/` – Malicious forwarding logic
- `data/` – Collected metrics (packet loss, power, sensor data)
- `images/` – Screenshots used for analysis and documentation
- `docs/` – Written documentation and articles

## Future Work

- Compare static vs dynamic node behavior
- Analyze power consumption impact in detail
- Explore traffic-level and anomaly-based detection mechanisms

## Author

Shreya Gajjar  
Cybersecurity | IoT Security | Network Security
