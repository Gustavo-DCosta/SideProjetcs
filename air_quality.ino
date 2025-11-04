void getAirqlt() {
  int q = sensor.slope();
  int val = sensor.getValue();

  Serial.print("Sensor value: ");
  Serial.println(val);

  lcd.clear();

  const char* msg1 = "";
  const char* msg2 = "";
  bool fanState = false;

  if (q == AirQualitySensor::FORCE_SIGNAL) {
    msg1 = "High pollution!";
    msg2 = "Force signal!";
    fanState = true;

  } else if (q == AirQualitySensor::HIGH_POLLUTION) {
    msg1 = "High pollution!";
    fanState = true;

  } else if (q == AirQualitySensor::LOW_POLLUTION) {
    msg1 = "Low pollution";

  } else if (q == AirQualitySensor::FRESH_AIR) {
    msg1 = "Fresh air";
  }

  fanState ? fanON() : fanOFF();

  lcd.setCursor(0, 0);
  lcd.print(msg1);
  if (msg2[0] != '\0') {
    lcd.setCursor(0, 1);
    lcd.print(msg2);
  }

  delay(2000);
}
