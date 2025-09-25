#include <arduino.h>

void mode3() {
  int a = 0;
  Serial.println("La boucle va marcher 3 fois|\_/|");
  while (a < 3) {
    if (digitalRead(btnStop) == LOW) break;
    if (a == 0) {
      for (int i = 0; i < 8; i++) {
        digitalWrite(leds[i], HIGH);
        delay(100);
        digitalWrite(leds[i], LOW);
        if (digitalRead(btnStop) == LOW) break;
      }
    } else if (a == 1) {
      for (int i = 0; i < 8; i += 2) {
        digitalWrite(leds[i], HIGH);
        delay(200);
        digitalWrite(leds[i], LOW);
        if (digitalRead(btnStop) == LOW) break;
      }
    } else if (a == 2) {
      for (int i = 0; i < 8; i += 3) {
        digitalWrite(leds[i], HIGH);
        delay(300);
        digitalWrite(leds[i], LOW);
        if (digitalRead(btnStop) == LOW) break;
      }
    }
    if (digitalRead(btnStop) == LOW) break;
    a++;
  }
}
