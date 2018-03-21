long DISTANCEUP (){
  delay(100);
  long data=0;  
  
  digitalWrite(trigPinUp, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPinUp, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinUp, LOW);
  data=pulseIn(echoPinUp, HIGH)/2;
  Serial.println("UP ");
  return data;
}
