# Project I (Minor): Original Report Extract

> Source: Chapter 4 of Shreya Gajjar’s April 2024 project/internship report. Text is transcribed from the supplied report; heading formatting and figure captions are normalized for GitHub. Figures are displayed only in the [figure gallery](../images/figures.md). Other projects and administrative pages are excluded.

## Analyzing Selective Forwarding Attacks in RPL with Contiki OS and Cooja Simulation.

## 4.1 Introduction

In the evolving landscape of the Internet of Things (IoT), the security of networked devices stands as a critical concern. IoT networks, characterized by their interconnectivity of everyday devices to the internet, are increasingly becoming integral to various sectors including healthcare, smart homes, and industrial control systems. This burgeoning integration, while offering unprecedented convenience and efficiency, also opens up new vulnerabilities and attack vectors for malicious entities. Among these, the security of network communications is paramount, as IoT devices often transmit sensitive data that could be compromised.

The Routing Protocol for Low-power and Lossy Networks (RPL) emerges as a cornerstone in this context, designed specifically to cater to the unique requirements of IoT networks. RPL facilitates efficient routing in environments characterized by high packet loss rates and limited power availability, common in IoT deployments. However, the reliance on RPL also introduces specific vulnerabilities, notably the threat of selective forwarding attacks. In such attacks, a malicious node within the network selectively drops packets, disrupting the network's functionality. This threat underscores the necessity of investigating and mitigating selective forwarding attacks to ensure the robustness and reliability of IoT networks.

Contiki OS, renowned for its lightweight and flexible design, offers an ideal platform for developing and testing IoT applications. Its compatibility with low-power IoT devices and support for simulating complex network topologies make it a preferred choice for security research in IoT networks. Coupled with the Cooja simulator, which allows for the detailed simulation of networks comprising both real and virtual nodes, researchers can meticulously analyze network behaviors under various conditions, including attack scenarios.

This study focuses on the simulation of selective forwarding attacks within an RPL-based IoT network using Contiki OS and the Cooja simulator. A significant aspect of our investigation centers on the role of malicious nodes — nodes programmed or compromised to perform selective forwarding attacks. By understanding the behavior and impact of these malicious nodes, the research aims to illuminate potential weaknesses within the RPL protocol and explore effective countermeasures.

Moreover, the project distinguishes between static and dynamic nodes, as well as nodes with and without mobility, to comprehensively assess the effects of node behavior on the network's vulnerability to selective forwarding attacks. Static nodes, fixed in their position, contrast with dynamic nodes, which may change location, potentially altering the network topology. Similarly, nodes with mobility introduce the challenge of maintaining consistent network connectivity and routing paths, further complicating the network's defense against selective forwarding attacks. By examining these different node types and behaviors, the study aims to provide nuanced insights into securing RPL-based IoT networks against selective forwarding attacks, thereby contributing to the overall security and reliability of IoT systems.

Through this project, we delve into the complexities of IoT network security, leveraging the capabilities of Contiki OS and the Cooja simulator to not only understand the threats posed by selective forwarding attacks but also to explore strategic defenses. The outcome of this research is anticipated to offer valuable contributions to the field of IoT security, particularly in enhancing the resilience of RPL-based networks against sophisticated attack mechanisms.

## 4.2 Background and Literature Review

### IoT Security Concerns

The proliferation of the Internet of Things (IoT) has interconnected billions of devices, embedding the internet into daily life and generating vast amounts of data. This advancement, however, brings to the forefront the importance of network security, especially for protocols like the Routing Protocol for Low-power and Lossy Networks (RPL). Designed for IoT's unique constraints, RPL facilitates efficient data transmission across constrained devices but is also susceptible to security threats, including selective forwarding attacks that can significantly undermine network integrity and reliability.

### Selective Forwarding Attacks

Selective forwarding attacks involve malicious nodes within an RPL network deliberately dropping packets, disrupting data flow. This can critically impact applications requiring reliable data transmission, such as health monitoring systems. The selective nature of these attacks makes detection and mitigation challenging, emphasizing a notable vulnerability in RPL-based networks.

### Contiki OS and Cooja Simulator

Contiki OS is a lightweight, open-source operating system optimized for IoT devices, enabling efficient development and deployment of IoT applications. It works hand-in-hand with the Cooja simulator, a tool that simulates Contiki OS nodes within IoT networks, allowing researchers to analyze network behavior under various scenarios, including security breaches. This combination is crucial for studying and enhancing IoT security.

### Previous Work

While numerous studies have investigated RPL's susceptibility to attacks, including selective forwarding, gaps remain in understanding how different node behaviors affect network security and the development of effective countermeasures. Moreover, there is a continuous need for research utilizing Contiki OS and Cooja to explore new threats and protection strategies. This project aims to fill these gaps by focusing on the dynamics of selective forwarding attacks within RPL-based IoT networks, leveraging the capabilities of Contiki OS and Cooja for comprehensive analysis and insights.

## 4.3 Project Objectives and Scope

### Objectives

Understand RPL's Behavior Under Selective Forwarding Attacks: To study how selective forwarding attacks affect the performance and reliability of RPL-based IoT networks.

Identify RPL Vulnerabilities: To pinpoint the weaknesses in RPL that are exploited by selective forwarding attacks.

Explore Mitigation Strategies: To develop and assess methods for reducing the impact of selective forwarding attacks on RPL networks.

### Scope

Simulation Environment: Utilizes Contiki OS and the Cooja simulator for simulating attacks in a controlled setting.

Attack Focus: Primarily concentrates on selective forwarding attacks, noting their relationship with other security threats for context.

Node Behaviors: The research will examine the effects of selective forwarding attacks considering various node behaviors, including static and dynamic nodes, as well as nodes with and without mobility. However, the study will acknowledge the limitations posed by the simulation environment in fully replicating real-world node mobility patterns.

Mitigation Limitations: Investigates mitigation strategies that can be implemented within the Contiki OS and Cooja simulator, recognizing that real-world applicability may require further exploration.

Figure 4.1 Working of Normal Network in Cooja simulation

Figure 4.2 Data Collection of Node in Network

Figure 4.3 Information status of Nodes

Figure 4.4  Sensor Data of Node Connection

Figure 4.5 Power Consumption of  Nodes in Normal Network

Figure 4.6 Power Consumption with one Dynamic Node ( Node with Mobility)

Figure 4.7 Data Collection  with one Dynamic Node ( Node with Mobility)

## 4.4 Scenario: Selective Forwarding Attack with Every 3rd Packet Dropped

### Network Setup

A simulated RPL-based IoT network in Contiki OS and Cooja includes one root node and several sensor nodes. A malicious node is introduced to execute the selective forwarding attack.

### Attack Mechanism

The malicious node is programmed to drop every 3rd packet it receives instead of forwarding it. This selective dropping aims to disrupt network reliability subtly.

### Objectives

Evaluate the impact on network performance, focusing on packet loss, latency, and reliability.

Examine RPL protocol resilience against selective forwarding attacks.

Explore detection and mitigation strategies for such attacks.

### Data Collection and Analysis

Metrics like packet loss rate and network latency are monitored to assess the attack's effect. The analysis will inform on the network's vulnerability and potential security enhancements.

Figure 4.8 Working and Temperature of Nodes ( With Malicious )

Figure 4.9  Node Information  ( With Malicious )

Figure 4.10 Output panel showing the sixth packet dropped (with malicious node).
