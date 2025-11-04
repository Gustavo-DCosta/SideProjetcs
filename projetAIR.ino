#include <Arduino.h>
#include "Air_Quality_Sensor.h"
#include <MQ2.h>
#include <SPI.h>
#include <Wire.h>
#include "rgb_lcd.h"

const int ventilo = 3;

AirQualitySensor sensor(A0);
MQ2 mq2(A2);
rgb_lcd lcd;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  mq2.begin();

  while (!Serial);
  delay(20000);

  if (sensor.init()) {
    lcd.print("Qt'air READY");
    Serial.println("READY");
  } else {
    lcd.print("Qt'air ERROR");
    Serial.println("ERROR");
  }

  pinMode(ventilo, OUTPUT);
}

void loop() {
  getAirqlt();
  getGasVal();
  

  delay(1000);
}
