# Hemodialysis Simulator

An Arduino-based hemodialysis simulation system with temperature monitoring and leak detection capabilities.

## Overview

This project simulates core aspects of a hemodialysis machine, focusing on:
- Temperature monitoring of dialysate fluid
- Water/blood flow detection
- Leak detection systems
- Pump control with safety mechanisms
- Real-time status display on OLED

## Hardware Components

- Arduino Uno/Nano/Mega
- Dallas DS18B20 Temperature Sensor
- IR Sensor (for leak/flow detection)
- SSD1306 OLED Display (128x64)
- 2x DC Water Pumps
- L298N Motor Driver Module
- 2x Buzzers (for different alerts)
- Jumper wires and breadboard
- Power supply

## Pin Configuration

| Component | Pin |
|-----------|-----|
| IR Sensor | D2 |
| Temperature Sensor | D3 |
| Buzzer 1 | D4 |
| Buzzer 2 | D5 |
| Motor Driver ENA | D6 |
| Motor Driver ENB | D7 |
| Pump 1 IN1 | D8 |
| Pump 1 IN2 | D9 |
| Pump 2 IN3 | D10 |
| Pump 2 IN4 | D11 |
| OLED SDA | A4 |
| OLED SCL | A5 |

## Features

- **Temperature Monitoring**: Continuously monitors dialysate temperature and shuts down if exceeds threshold (25°C)
- **Flow Detection**: Uses IR sensor to detect proper fluid flow
- **Leak Detection**: Alerts with dedicated buzzer if potential leak detected
- **Pump Control**: Variable speed control for simulating different flow rates
- **OLED Display**: Real-time information about system status
- **Safety Systems**: Automatic shutdown during dangerous conditions

## Installation and Setup

1. Connect all components according to the pin configuration
2. Install required libraries:
   - OneWire
   - DallasTemperature
   - Wire
   - Adafruit_GFX
   - Adafruit_SSD1306
3. Upload the code to your Arduino
4. Connect power supply to the motor driver
5. Arrange tubing for water circulation

## Operation Instructions

The system operates with the following logic:
- Normal operation: Both pumps run at specified speeds, no alarms
- Temperature exceeds threshold: Pumps stop, Buzzer 1 activates
- Flow/leak issue detected: Pumps stop, Buzzer 2 activates
- Current status displayed on OLED screen

## Customization

You can modify these parameters in the code:
- `TEMP_THRESHOLD`: Temperature limit (default: 25.0°C)
- `pumpSpeed`: Motor speed (default: 130, range: 0-255)

## Future Improvements

- Add pressure sensors
- Implement flow rate calculation
- Add data logging capabilities
- Create mobile app connectivity

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Inspired by principles of hemodialysis machines
- Created for educational and demonstration purposes
