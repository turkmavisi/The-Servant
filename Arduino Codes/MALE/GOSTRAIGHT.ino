void GOSTRAIGHT (int d){
  Serial.println("Go straight");
  digitalWrite (R0, LOW);
  digitalWrite (R1, HIGH);
  digitalWrite (L0, LOW);
  digitalWrite (L1, HIGH);
  
  analogWrite (pwmR, 255); //was250
  analogWrite (pwmL, 160);
  delay(d);
}
