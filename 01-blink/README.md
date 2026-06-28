# 01 — ESP32 Blink (Toolchain Verification)

## Overview
First contact with the ESP32 DevKit V1. This project verifies that the full
development toolchain is correctly installed and working on antiX Linux.
It also serves as a complete setup walkthrough for anyone starting from scratch.

## What it does
Blinks the built-in LED (GPIO 2) on and off in a 2-second interval loop.

## Hardware Required
- ESP32 DevKit V1
- USB cable only — no wiring or breadboard needed

## Tools & Environment
- PlatformIO + VS Code
- Arduino framework
- antiX Linux (Debian-based)

## Setup & Walkthrough

### 1. Verify Python is installed
```bash
python3 --version
```
Python 3.8 or above is required for PlatformIO to work.

### 2. Check user group access
```bash
groups
```
You must see `dialout` in the list. Without it, Linux will block access
to the ESP32 serial port. If missing, run:
```bash
sudo usermod -aG dialout $USER
```
Then log out and back in for it to take effect.

### 3. Install VS Code
Download the .deb package from https://code.visualstudio.com and run:
```bash
sudo dpkg -i vscode.deb
sudo apt --fix-broken install -y
```
Verify with:
```bash
code --version
```

### 4. Install PlatformIO extension
```bash
code --install-extension platformio.platformio-ide
```
Open VS Code and wait for PlatformIO to finish its first-time setup.
The ant icon 🐜 will appear in the left sidebar when ready.

### 5. Create project & flash
- New Project → Board: ESP32 Dev Module → Framework: Arduino
- Write your code in src/main.cpp
- Click Upload (→) in the bottom blue bar

### 6. Verify ESP32 is detected
Plug in via USB, then run:
```bash
ls /dev/ttyUSB*
```
You should see `/dev/ttyUSB0`. If nothing appears, check your USB cable
— some cables are charge-only and cannot transfer data.

### 7. Manual flash mode
If upload fails with "Unable to verify flash chip connection":
- Hold BOOT button on the ESP32
- Press and release EN button
- Release BOOT
- Click Upload immediately

## How to Flash & Run
1. Open this folder in VS Code with PlatformIO installed
2. Connect ESP32 via USB
3. Click Upload (→) — hold BOOT + press EN if needed
4. Built-in blue LED will start blinking

## Key Takeaways
1. GPIO 2 is the built-in LED pin on ESP32 DevKit V1
2. PlatformIO needs manual BOOT + EN trigger on first flash for this board
3. dialout group membership is required on Linux to access /dev/ttyUSB0
4. delay() is in milliseconds: delay(2000) = 2 seconds

## Part of
[esp32-iot-security-portfolio](../README.md) — Project 1 of 4