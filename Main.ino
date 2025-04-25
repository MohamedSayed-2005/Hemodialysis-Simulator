#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
#define IR_SENSOR_PIN 2
#define TEMP_SENSOR_PIN 3
#define BUZZER1_PIN 4
#define BUZZER2_PIN 5
#define ENA_PIN 6
#define ENB_PIN 7
#define PUMP1_IN1 8
#define PUMP1_IN2 9
#define PUMP2_IN3 10
#define PUMP2_IN4 11

// Temperature
OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature sensors(&oneWire);
float temperatureC;
const float TEMP_THRESHOLD = 25.0; // Over-temp alert
const int pumpSpeed = 130;  // Adjust speed (0 to 255)


void setup() {
  Serial.begin(9600);
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER1_PIN, OUTPUT);
  pinMode(BUZZER2_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(PUMP1_IN1, OUTPUT);
  pinMode(PUMP1_IN2, OUTPUT);
  pinMode(PUMP2_IN3, OUTPUT);
  pinMode(PUMP2_IN4, OUTPUT);
  
  sensors.begin();
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); // Freeze if OLED fails
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("System Initializing...");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  int irDetected = digitalRead(IR_SENSOR_PIN);
  sensors.requestTemperatures();
  temperatureC = sensors.getTempCByIndex(0);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Hemodialysis Sim:");
  display.setCursor(0, 16);
  display.print("Temp: ");
  display.print(temperatureC);
  display.println(" C");
  display.setCursor(0, 32);

  if (irDetected == HIGH) {
    display.println("Water Flow Detected");

    if (temperatureC <= TEMP_THRESHOLD) {
     // Run Pumps with speed control
      analogWrite(ENA_PIN, 90);  // Pump 1
      analogWrite(ENB_PIN, pumpSpeed);  // Pump 2
      digitalWrite(PUMP1_IN1, HIGH);
      digitalWrite(PUMP1_IN2, LOW);
      digitalWrite(PUMP2_IN3, HIGH);
      digitalWrite(PUMP2_IN4, LOW);


      digitalWrite(BUZZER1_PIN, LOW);
      digitalWrite(BUZZER2_PIN, LOW);
      display.setCursor(0, 48);
      display.println("Pumps ON");
    } else {
      // Over Temp Alert
      stopPumps();
      digitalWrite(BUZZER1_PIN, HIGH);
      display.setCursor(0, 48);
      display.println("Over Temp!");
    }

  } else {
    stopPumps();
    digitalWrite(BUZZER2_PIN, HIGH);
    display.println("Blood Leakage detected");
    display.setCursor(0, 48);
    display.println("Pumps OFF");
  }

  display.display();
  delay(1000);
}

void stopPumps() {
  analogWrite(ENA_PIN, 0);
  analogWrite(ENB_PIN, 0);
  digitalWrite(PUMP1_IN1, LOW);
  digitalWrite(PUMP1_IN2, LOW);
  digitalWrite(PUMP2_IN3, LOW);
  digitalWrite(PUMP2_IN4, LOW);
}