# Hemodialysis Simulator: Components List

This document provides detailed specifications for all components required to build the hemodialysis simulator, along with suggested alternatives and purchasing information.

## Microcontroller

**Arduino Uno R3** (Recommended)
- Operating Voltage: 5V
- Digital I/O Pins: 14 (of which 6 provide PWM output)
- Analog Input Pins: 6
- DC Current per I/O Pin: 20 mA
- Flash Memory: 32 KB

**Alternatives:**
- Arduino Nano (smaller footprint)
- Arduino Mega (more I/O pins if expanding the project)

## Sensors

### Temperature Sensor
**DS18B20 Waterproof Digital Temperature Sensor**
- Temperature Range: -55°C to +125°C
- Accuracy: ±0.5°C from -10°C to +85°C
- Resolution: 9-12 bit (programmable)
- Interface: 1-Wire interface
- Power Supply: 3.0V to 5.5V
- Waterproof probe length: ~100cm

**Alternatives:**
- TMP36 Analog Temperature Sensor (less accurate but simpler to interface)

### IR Sensor
**IR Infrared Obstacle Avoidance Sensor Module**
- Operating Voltage: 3.3V-5V
- Detection Range: 2-30cm (adjustable)
- Output: Digital (HIGH/LOW)
- With potentiometer for sensitivity adjustment

**Alternatives:**
- Photoelectric Water/Liquid Level Sensor
- Capacitive liquid level sensor

## Display

**SSD1306 OLED Display**
- Display Size: 0.96 inch
- Resolution: 128×64 pixels
- Interface: I2C
- Operating Voltage: 3.3-5V
- Color: Blue/White/Yellow+Blue
- I2C Address: 0x3C (or 0x3D)

**Alternatives:**
- Larger 1.3" SSD1306 OLED
- LCD 16x2 with I2C adapter (less graphical capability but simpler to use)

## Motor Control

**L298N Motor Driver Module**
- Motor Supply Voltage (VSS): 5V-35V
- Logic Voltage (VSS): 5V
- Peak Current: 2A per channel
- Enables dual H-bridge motor driver
- Comes with heat sink for better heat dissipation

**Alternatives:**
- L293D Motor Driver Shield
- TB6612FNG Motor Driver (more efficient, less heat)

## Pumps

**DC Water Pump** (need 2)
- Operating Voltage: 6-12V DC
- Current: ~300-400mA
- Flow Rate: ~120-200L/H
- Lift Height: ~1.5-2m
- Waterproof
- With output nozzle fitting standard tubing

**Alternatives:**
- Peristaltic pumps (more precise, gentler on fluids, but more expensive)

## Alert System

**Active Buzzer Module** (need 2)
- Operating Voltage: 5V
- High sound output
- TTL level control

**Alternatives:**
- Piezo speakers
- LED indicators (for visual alerts instead of sound)

## Miscellaneous

### Power Supply
- 12V 2A DC Adapter (for powering pumps via L298N)
- USB cable for Arduino

### Connection Materials
- Breadboard (for prototyping)
- Jumper Wires (male-to-male, male-to-female, female-to-female)
- Silicone tube (8mm inner diameter)
- Water containers/reservoirs
- Project enclosure box

### Optional Components for Expansion
- Flow rate sensor (YF-S201)
- Pressure sensors (MPX5010DP)
- Real-time clock module (DS3231)
- SD card module (for data logging)
- Bluetooth module (HC-05) for wireless monitoring

## Estimated Budget

| Component | Quantity | Est. Price (USD) |
|-----------|----------|------------------|
| Arduino Uno | 1 | $20-25 |
| DS18B20 Temp Sensor | 1 | $3-5 |
| IR Sensor | 1 | $2-3 |
| SSD1306 OLED | 1 | $5-8 |
| L298N Motor Driver | 1 | $4-6 |
| DC Water Pumps | 2 | $8-12 |
| Buzzers | 2 | $1-2 |
| Power Supply | 1 | $8-12 |
| Breadboard & Wires | - | $10-15 |
| Tubing & Containers | - | $5-10 |
| **TOTAL** | | **$66-98** |

## Purchasing Resources

These components can be found at:
- Online: Amazon, eBay, AliExpress, Adafruit, SparkFun
- Local: Electronics stores, hardware stores, hobby shops

## Notes on Component Selection

1. **Water Resistance**: Since this project involves water, consider waterproofing critical components or mounting them away from potential water exposure.

2. **Power Requirements**: Ensure your power supply can handle the current requirements of both pumps operating simultaneously (typically 600-800mA total).

3. **Sensor Precision**: For more accurate simulation, consider upgrading to medical-grade sensors if budget allows.

4. **Tubing**: Medical grade silicone tubing provides better durability and is easier to clean if doing extended demonstrations.
