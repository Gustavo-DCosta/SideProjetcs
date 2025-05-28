#include <DHT11.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#define I2C_ADDRESS 0x3C
SSD1306AsciiAvrI2c oled;

const int lum = A0;
const int presence = A1;
const int gas_censor = A2;

const int led_ext = 3;
const int buzzer = 4;

DHT11 dht11(2);

void setup() {
  Serial.begin(9600);
  Serial.println("---------------- Arduino en marche ------------------------");
  pinMode(lum, INPUT);
  pinMode(presence, INPUT);
  pinMode(gas_censor, INPUT);
  
  pinMode(buzzer, OUTPUT); // Définir le buzzer comme une sortie
}

void loop() {
  float niv_lum = analogRead(lum);
  float niv_gas = analogRead(gas_censor);
  int mvt = digitalRead(presence);
  int temperature = 0;
  int humidity = 0;

  if (mvt == HIGH) {
    delay(200);
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
    oled.setFont(Adafruit5x7);
    oled.clear();
    oled.set2X();
    oled.println("Bienvenue!");
    delay(10000); //delay de 10 secondes
    oled.clear();
  }

  Serial.print("Niveau lumiere: ");
  Serial.println(niv_lum);

  Serial.print("Niveau gas: ");
  Serial.println(niv_gas);

  Serial.println("  "); //ligne blanche

 
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  if (result == 0) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }__

    // Activer le buzzer si la température dépasse 25°C ou si le niveau de gaz est supérieur à 600
  if (temperature > 25 || niv_gas > 650) {
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500); 
  }
  } else {
    // Print error message based on the error code.
    Serial.println(DHT11::getErrorString(result));
  }

  delay(300);
}