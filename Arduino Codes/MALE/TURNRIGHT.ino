void TURNRIGHT (int d){
  Serial.println("Turn right");
  digitalWrite (L0, LOW);
  digitalWrite (L1, HIGH);
  digitalWrite (R0,HIGH);
  digitalWrite (R1, LOW);
  
  analogWrite (pwmR, 250);
  analogWrite (pwmL, 250);
  delay(d);
}
