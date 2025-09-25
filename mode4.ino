#include <arduino.h>

void mode4() {
  for (int i=0; i<8; i++) {
    digitalWrite(leds[i], HIGH);
    delay(100);
    if (i == 8) {
      for (int i=8; i >0;i--) {
        digitalWrite(leds, LOW);
      }
    }
  }
}