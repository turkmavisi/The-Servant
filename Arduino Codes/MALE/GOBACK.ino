void GOBACK (int d){
  Serial.println("Go back");
  digitalWrite (R0, HIGH);
  digitalWrite (R1, LOW);
  digitalWrite (L0, HIGH);
  digitalWrite (L1, LOW);
  
  analogWrite (pwmR, 200);
  analogWrite (pwmL, 200);
  delay(d);

}
