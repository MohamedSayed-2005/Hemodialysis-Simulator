# Hemodialysis Simulator: Detailed Setup Guide

This guide provides step-by-step instructions for setting up your Arduino-based hemodialysis simulator.

## Table of Contents
- [Hardware Assembly](#hardware-assembly)
- [Software Installation](#software-installation)
- [Testing the System](#testing-the-system)
- [Troubleshooting](#troubleshooting)

## Hardware Assembly

### 1. Connect the OLED Display
- Connect SDA to Arduino A4
- Connect SCL to Arduino A5
- Connect VCC to Arduino 5V
- Connect GND to Arduino GND

### 2. Connect the Temperature Sensor (DS18B20)
- Connect the data pin to Arduino D3
- Connect VCC to Arduino 5V
- Connect GND to Arduino GND
- Add a 4.7kΩ pull-up resistor between the data pin and VCC

### 3. Connect the IR Sensor
- Connect OUT to Arduino D2
- Connect VCC to Arduino 5V
- Connect GND to Arduino GND

### 4. Connect the L298N Motor Driver
- Connect ENA to Arduino D6
- Connect ENB to Arduino D7
- Connect IN1 to Arduino D8
- Connect IN2 to Arduino D9
- Connect IN3 to Arduino D10
- Connect IN4 to Arduino D11
- Connect the driver's 5V output to Arduino 5V (if using same power source)
- Connect GND to Arduino GND
- Connect external power supply (7-12V) to the driver's power input

### 5. Connect the Water Pumps
- Connect Pump 1 to motor driver output terminals A
- Connect Pump 2 to motor driver output terminals B

### 6. Connect the Buzzers
- Connect Buzzer 1 positive to Arduino D4, negative to GND
- Connect Buzzer 2 positive to Arduino D5, negative to GND

### 7. Final Assembly Notes
- Ensure all connections are secure and properly insulated
- Mount components on a stable platform
- Arrange water tubing in a closed loop for testing
- Use containers for water reservoirs

## Software Installation

### 1. Install Required Libraries
Open Arduino IDE and install the following libraries through Library Manager (Tools > Manage Libraries):
- OneWire
- DallasTemperature
- Adafruit_GFX
- Adafruit_SSD1306

### 2. Upload the Code
- Connect your Arduino to your computer via USB
- Open the HemodialysisSimulator.ino file in Arduino IDE
- Select your Arduino board type (Tools > Board)
- Select the correct port (Tools > Port)
- Click Upload

## Testing the System

### 1. Initial Power-Up Test
- Connect Arduino to USB power (or external power supply)
- The OLED should initialize and display "System Initializing..."
- After 2 seconds, it should switch to the main interface

### 2. Temperature Sensor Test
- The OLED should display the current temperature
- Verify that the temperature reading changes when the sensor is warmed or cooled

### 3. IR Sensor Test
- Place an object in front of the IR sensor
- The display should show "Water Flow Detected"
- Remove the object, should show "Blood Leakage detected"

### 4. Pump Operation Test
- With IR sensor detecting flow and temperature below threshold:
  - Both pumps should activate
  - OLED should display "Pumps ON"
- With temperature above threshold:
  - Pumps should stop
  - Buzzer 1 should sound
  - OLED should display "Over Temp!"
- With IR sensor not detecting flow:
  - Pumps should stop
  - Buzzer 2 should sound
  - OLED should display "Blood Leakage detected"

## Troubleshooting

### OLED Not Displaying
- Check I2C address (default 0x3C, might be 0x3D on some displays)
- Verify Wire connections to A4/A5
- Confirm library installation

### Temperature Sensor Not Reading
- Verify 4.7kΩ pull-up resistor is installed
- Check OneWire connection
- Try replacing the sensor

### Pumps Not Working
- Check L298N connections
- Verify external power supply is adequate
- Check that PWM pins (ENA/ENB) are properly connected

### IR Sensor Issues
- Adjust sensitivity (if your sensor has a potentiometer)
- Check for proper power supply
- Test with different objects/distances

### System Resets or Behaves Erratically
- Ensure adequate power supply for all components
- Add capacitors near power inputs to reduce noise
- Separate digital and analog grounds if possible
