const int led1 = 6;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;
const int led5 = 10;
const int led6 = 11;
const int led7 = 12;
const int led8 = 13;

const int btnStart = 2;

const int btnStop = 5;


void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

  pinMode(btnStart, INPUT_PULLUP);
}

void loop() {
  int leds[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };

  int reader = digitalRead(btnStart);
  int breaker = digitalRead(btnStop);

  if (reader == 1) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(leds[i], HIGH);
      delay(300);
      digitalWrite(leds[i], LOW);
      delay(300);
      Serial.println(i);
    }

    for (int i = 8; i > 0; i--) {
      digitalWrite(leds[i], HIGH);
      delay(300);
      digitalWrite(leds[i], LOW);
      delay(300);
      Serial.println(i);
    }
  }
}
