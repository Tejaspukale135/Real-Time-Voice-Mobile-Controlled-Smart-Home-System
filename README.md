# Real-Time Voice & Mobile Controlled Smart Home System

## Project Overview

An ESP32-based smart home system developed to control three electrical appliances using relay modules, Wi-Fi communication, and a user control interface.

The project was developed in two stages:

- Local web-based control using ESP32 Access Point and WebServer
- Blynk-based Wi-Fi control for mobile operation

## Hardware

- ESP32 Development Board
- 3-Channel Relay Module
- White Light
- DC Motor Fan
- Blue Light

## GPIO Configuration

| ESP32 GPIO | Device |
|---|---|
| GPIO 23 | White Light |
| GPIO 22 | Fan |
| GPIO 21 | Blue Light |

## Relay Logic

The relay module uses active-LOW logic

## Development Stage 1 — Local Web Control

The first implementation used the ESP32 as a Wi-Fi Access Point.

The system used:

- ESP32 SoftAP
- WebServer
- DNSServer
- Local web interface
- Three relay controls

The user could connect to the ESP32 Wi-Fi network and control the three relay channels through a web interface.

## Development Stage 2 — Blynk Control

The system was later modified to use Blynk for Wi-Fi-based control.

The virtual pins were configured as:

| Blynk Virtual Pin | Device |
|---|---|
| V0 | White Light |
| V1 | Fan |
| V2 | Blue Light |

## Software

- Arduino IDE
- ESP32
- C/C++
- Wi-Fi
- WebServer
- DNSServer
- Blynk

## Testing

The system was tested for:

- ESP32 initialization
- Wi-Fi connectivity
- Web interface operation
- Blynk connectivity
- Relay ON/OFF operation
- Individual appliance control
- System response and stability

## Project Development

### Stage 1

Implemented local appliance control using an ESP32-hosted web interface.

### Stage 2

Modified the system to use Blynk for Wi-Fi-based mobile control.

## Project Outcome

The developed system provides wireless control of three connected appliances through an ESP32 and relay interface.

The project demonstrates practical implementation of:

- ESP32 GPIO control
- Relay interfacing
- Wi-Fi communication
- Embedded programming
- Web-based control
- Blynk-based IoT control
- Hardware integration
- System testing

## Applications

- Smart home automation
- Wireless appliance control
- IoT-based embedded systems
- Remote appliance switching

## Future Scope

- Energy monitoring
- Additional sensors
- Scheduling
- Security monitoring
- Notification systems
- Additional appliance channels

```text
LOW  → Relay ON
HIGH → Relay OFF
