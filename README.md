# -IOT-Based-Proactive-Disaster-Detection

# IoT Based Proactive Disaster Detection

This project implements an IoT-based proactive disaster detection system. The system uses various sensors to monitor environmental conditions and detect potential disasters such as gas leaks, fires, and extreme weather conditions. The data collected by the sensors is sent to the ThingSpeak cloud platform for real-time monitoring and analysis.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)

## Introduction

The IoT-based proactive disaster detection system aims to provide early warnings for potential disasters by continuously monitoring environmental parameters. The system includes sensors for detecting temperature, humidity, LPG gas, carbon monoxide, smoke, and distance. The data collected by these sensors is sent to the ThingSpeak cloud platform for further analysis and visualization.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- DHT11 temperature and humidity sensor
- MQ2 gas sensor
- Ultrasonic sensor (HC-SR04)
- Ethernet shield
- Jumper wires
- Breadboard (optional)

## Software Requirements

- Arduino IDE
- ThingSpeak library for Arduino
- DHT sensor library for Arduino
- MQ2 sensor library for Arduino

## Setup and Installation

1. **Connect the sensors:**
   - **DHT11 sensor:**
     - Connect VCC to 5V
     - Connect GND to GND
     - Connect data pin to digital pin 8
   - **MQ2 sensor:**
     - Connect VCC to 5V
     - Connect GND to GND
     - Connect analog output pin to analog pin A3
   - **Ultrasonic sensor (HC-SR04):**
     - Connect VCC to 5V
     - Connect GND to GND
     - Connect trig pin to analog pin A2
     - Connect echo pin to analog pin A1

2. **Install the Arduino IDE:**
   - Download and install the Arduino IDE from the [official website](https://www.arduino.cc/en/software).

3. **Install the necessary libraries:**
   - Open the Arduino IDE and go to **Sketch** > **Include Library** > **Manage Libraries...**
   - Search for "ThingSpeak" and install the ThingSpeak library.
   - Search for "DHT sensor library" and install the DHT sensor library.
   - Search for "MQ2" and install the MQ2 sensor library.

4. **Upload the code:**
   - Copy the provided code into the Arduino IDE.
   - Connect your Arduino board to your computer using a USB cable.
   - Select the appropriate board and port from the Tools menu.
   - Upload the code to your Arduino board.

## Usage

1. **Power the Arduino:** Ensure the Arduino board is powered either through a USB connection to your computer or an external power source.
2. **Monitor the Serial Output:** Open the Serial Monitor from the Arduino IDE to view the sensor readings.
3. **Check ThingSpeak:** Go to your ThingSpeak channel to view the real-time data and visualize the environmental parameters.

