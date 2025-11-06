#include <Servo.h>

Servo servoVertical;
Servo servoHorizontal;

void setup() {
  Serial.begin(9600);
  servoVertical.attach(7);
  servoHorizontal.attach(8);
}

void loop() {
  int valueVertical = analogRead(A0);
  int valueHorizontal = analogRead(A1);

  Serial.print("Y:");
  Serial.print(valueVertical);
  Serial.print(" X:");
  Serial.println(valueHorizontal);

  // Map joystick range to servo angle range
  int valHB = map(valueVertical, 0, 1023, 3, 177);
  int valGD = map(valueHorizontal, 0, 1023, 3, 177);

  Serial.print("valHB =");
  Serial.println(valHB );
  
  servoVertical.write(valHB);
  servoHorizontal.write(valGD);

  delay(100);
}
