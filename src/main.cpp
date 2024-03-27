#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_AHTX0.h>
#include <Fonts/FreeSans9pt7b.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C display=LiquidCrystal_I2C(0x27,20,4);
Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(115200);
  //while (!Serial);

  display.init();              
  display.backlight();

  if (aht.begin()) {
    Serial.println("Found AHT20");
  } else {
    Serial.println("Didn't find AHT20");
  }  
}

void loop() {
  sensors_event_t humidity, temp;
  
  aht.getEvent(&humidity, &temp);
  display.setCursor(4,0);
  display.print("AHT20 Demo");
  display.setCursor(0,1);
  display.print("Temp: "); display.print(temp.temperature); display.print(" C");
  display.setCursor(0,2);
  display.print("Hum: "); display.print(humidity.relative_humidity); display.print(" %");
  Serial.print("Temperature: ");Serial.print(temp.temperature);Serial.print(" degrees C");
  Serial.print("Pressure: ");Serial.print(humidity.relative_humidity);Serial.print(" RH %");
  
  delay(1000);
}
