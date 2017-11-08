#include <stdio.h>

// LCD header
#include <LiquidCrystal.h>

// our Sensor header 
#include "SensorMonitor.h"


// Pins:
const byte LCD_RS = 12;
const byte LCD_EN = 11;
const byte LCD_D4 = 5;
const byte LCD_D5 = 4;
const byte LCD_D6 = 3;
const byte LCD_D7 = 2;

const byte DHT_PIN = 7;


// devices
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

SensorMonitor sensorMonitor(DHT_PIN);


void setup() {
  // setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  // prepare Peripherals..
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
  // main code here, to run repeatedly:
  //  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(500);                       // wait for a second
  //  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //  delay(500);                       // wait for a second

  float temp, hum;
  int ret = sensorMonitor.readValues(temp, hum);
  if(ret != 0) {
    Serial.print("Failed to read values... trying again.\n");
    delay(1000);
    return;
  }

  Serial.print("Temperature: "); Serial.print(temp);
  Serial.print(", Humidity: "); Serial.print(hum);
  Serial.print("\n");

  lcd.clear();
  lcd.print(hum);
  
  delay(1000);
}


