long DISTANCELOW (){
  delay(100);
  long data=0;
    
  digitalWrite(trigPinLow, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPinLow, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLow, HIGH);
  data=pulseIn(echoPinLow, HIGH)/2;
  Serial.println("LOW ");
  return data;
}
