void TURNLEFT (int d){
  Serial.println("Turn left");
  digitalWrite (R0, LOW);
  digitalWrite (R1, HIGH);
  digitalWrite (L0,HIGH);
  digitalWrite (L1, LOW);

  analogWrite (pwmR, 255);
  analogWrite (pwmL, 255);
  delay(d);
}
