void GOSLOW(int d){
  Serial.println("Go slow");
  digitalWrite (R0, LOW);
  digitalWrite (R1, HIGH);
  digitalWrite (L0, LOW);
  digitalWrite (L1, HIGH);
  
  analogWrite (pwmR, 200);
  analogWrite (pwmL, 200);
  delay(d); 
}

