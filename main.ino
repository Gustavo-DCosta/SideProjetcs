#include <arduino.h>

const int leds[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };
const int ledsABC[6] = { 8, 9, 10, 11, 12, 13 };

const int btnMd1 = 2;
const int btnMd2 = 3;
const int btnMd3 = 4;
const int btnStop = 5;
const int pot = A2;

void setup() {
  Serial.begin(9600);

  pinMode(btnMd1, INPUT_PULLUP);
  pinMode(btnMd2, INPUT_PULLUP);
  pinMode(btnMd3, INPUT_PULLUP);
  pinMode(btnStop, INPUT_PULLUP);
  pinMode(pot, INPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int reader1 = digitalRead(btnMd1);
  int reader2 = digitalRead(btnMd2);
  int reader3 = digitalRead(btnMd3);
  int pot_reader = analogRead(pot);

  Serial.println(pot_reader);

  if (reader1 == LOW) {
    mode1();
  } else if (reader2 == LOW) {
    mode2();
  } else if (reader3 == LOW) {
    mode3();
  } else if (reader1 && reader2 == LOW) {
    mode4();
  }

  if (pot_reader == 0 && pot_reader <= 145) {
    digitalWrite(ledsABC, LOW);
  } else if (pot_reader >= 146 && pot_reader <= 291) {
    digitalWrite(ledsABC[1], HIGH);
  } else if (pot_reader >= 292 && pot_reader <= 437) {
    modPot2();
  } else if (pot_reader >= 438 && pot_reader <= 583) {
    modPot3();
  } else if (pot_reader >= 584 && pot_reader <= 730) {
    modPot4();
  } else if (pot_reader >= 876 && pot_reader <= 1024) {
    modPot5();
  }
}