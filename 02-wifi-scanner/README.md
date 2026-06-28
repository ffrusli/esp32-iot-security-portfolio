# 02 — ESP32 Wi-Fi Security Scanner

## Overview
A lightweight IoT security tool that scans nearby Wi-Fi networks every 10 seconds
and flags unsecured (open) access points in real time. 

## Security Relevance
Open Wi-Fi networks expose users to man-in-the-middle attacks, packet sniffing,
and session hijacking. This tool helps identify unsecured access points in any
environment — useful for basic wireless security audits.

## Hardware Used
- ESP32 DevKit V1
- Micro-USB cable

## Tools & Environment
- PlatformIO + VS Code
- Arduino framework
- antiX Linux (Debian-based)
- ESP32 built-in WiFi library

## How to Flash & Run
1. Open this folder in VS Code with PlatformIO installed
2. Connect ESP32 via USB
3. Click Upload (→) — hold BOOT + press EN if needed
4. Open Serial Monitor at 115200 baud
5. Watch live scan results update every 10 seconds

## Sample Output
```
--- Scanning Networks ---
1. NETGEAR24_EXT | Signal: -54 dBm | SECURED
2. Livebox-6C40 | Signal: -75 dBm | SECURED
--- Scan Complete --
```

## Key Concepts Demonstrated
- ESP32 WiFi library (WIFI_STA mode)
- UART Serial communication at 115200 baud
- Encryption type detection (WPA/WPA2 vs open)
- Periodic scanning with delay loop

## Key Takeaways
1. ESP32 must be in WIFI_STA mode to scan:  it cannot scan in AP (hotspot) mode
2. RSSI signal strength is measured in negative dBm: closer to 0 means stronger (e.g. -45 dBm is stronger than -80 dBm)
3. Hidden networks may appear with an empty SSID: they are not truly invisible, just unnamed, and still detectable by scanners
4. Open networks (WIFI_AUTH_OPEN) have zero encryption: any traffic on them can be intercepted without special tools
5. Both sides of a serial connection must agree on the same baud rate: mismatched rates produce gibberish output
6. Standard baud rate for ESP32 serial debugging is 115200, but if unknown, you can try standard agreed values (9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600) until the output stops being gibberish.

## Part of
[esp32-iot-security-portfolio](../README.md) — Project 2 of 4
