void getGasVal() {
  float lpg = mq2.readLPG();
  float co = mq2.readCO();
  float smoke = mq2.readSmoke();

  // Thresholds (tune these depending on your sensor and environment)
  float LPG_THRESHOLD = 5.0;    // ppm
  float CO_THRESHOLD = 6.0;     // ppm
  float SMOKE_THRESHOLD = 5.0;  // ppm

  // Print to Serial (debugging vibes)
  Serial.print("LPG: "); Serial.print(lpg); Serial.print(" ppm  ");
  Serial.print("CO: "); Serial.print(co); Serial.print(" ppm  ");
  Serial.print("Smoke: "); Serial.print(smoke); Serial.println(" ppm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LPG:");
  lcd.print(lpg, 1);
  lcd.print(" CO:");
  lcd.print(co, 1);

  lcd.setCursor(0, 1);
  lcd.print("Smoke:");
  lcd.print(smoke, 1);
  lcd.print("ppm");

  // --- FAN CONTROL SECTION ---
  // If *any* gas level is too high -> turn fan ON
  if (lpg > LPG_THRESHOLD || co > CO_THRESHOLD || smoke > SMOKE_THRESHOLD) {
    fanON();
  } else {
    fanOFF();
  }

  delay(2000);
}