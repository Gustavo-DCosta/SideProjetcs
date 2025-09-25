#include <arduino.h>

void mode1() {
  while (true) {
    if (digitalRead(btnStop) == LOW) break;
    for (int i = 0; i < 8; i++) {
      digitalWrite(leds[i], HIGH);
      delay(75);
      digitalWrite(leds[i], LOW);
      if (digitalRead(btnStop) == LOW) break;
    }
    for (int i = 8 - 1; i >= 0; i--) {
      digitalWrite(leds[i], HIGH);
      delay(75);
      digitalWrite(leds[i], LOW);
      if (digitalRead(btnStop) == LOW) break;
    }
    if (digitalRead(btnStop) == LOW) break;
  }
}