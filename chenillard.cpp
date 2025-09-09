int leds[8] = { 6, 7, 8, 9, 10, 11, 12, 13 }; 

const int btnStart = 2;
const int btnStop = 5; 

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnStop, INPUT_PULLUP);
}

void loop() {
  int reader = digitalRead(btnStart);
  int breaker = digitalRead(btnStop);

  if (reader == 0) {
    for (int i = 0; i < 8; i++) {
      if (breaker == 0) {
        break;
      }
      digitalWrite(leds[i], HIGH);
      delay(1000);
      digitalWrite(leds[i], LOW);
      delay(1000);
      Serial.println(i);
      if (breaker == 0) {
        break;
      }
    }
    for (int i = 8; i > 0; i--) {
      if (breaker == 0) {
        break;
      }
      digitalWrite(leds[i], HIGH);
      delay(1000);
      digitalWrite(leds[i], LOW);
      delay(1000);
      Serial.println(i);
      if (breaker == 0) {
        break;
      }
    }
  }
}
