#include <arduino.h>

void mode2() {
  int a = 0;
  while (a<5) {
    if (digitalRead(btnStop) == LOW) break;
    for (int i = 4; i > 0; i--) {
      digitalWrite(leds[i], HIGH);
      delay(100);
      digitalWrite(leds[i], LOW);
      if (digitalRead(btnStop) == LOW) break;
    }
    for (int i = 4; i < 8; i++) {
      digitalWrite(leds[i], HIGH);
      delay(100);
      digitalWrite(leds[i], LOW);
      if (digitalRead(btnStop) == LOW) break;
    }
    if (digitalRead(btnStop) == LOW) break;
    a++;
  }
}