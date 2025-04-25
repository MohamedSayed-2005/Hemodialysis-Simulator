# Hemodialysis Simulator  
![Banner](/docs/images/project-banner.jpg)  

## Features  
- Temperature monitoring (DS18B20 sensor)  
- Blood leakage detection (IR sensor)  
- Dual-pump control (L298N driver)  
- OLED status display  

## Hardware  
- Arduino Uno  
- DS18B20 Sensor  
- IR Sensor  
- SSD1306 OLED  
- 2x DC Pumps  

## Setup  
1. Clone this repo.  
2. Open `Hemodialysis_Sim.ino` in Arduino IDE.  
3. Install libraries:  
   ```bash
   OneWire
   DallasTemperature
   Adafruit_GFX
   Adafruit_SSD1306
