void WAIT(){
  Serial.println("Wait");
  digitalWrite(com,HIGH);
  Serial.println("high");
  digitalWrite(com,LOW);
  Serial.println("low");
  delay(100);
  pinMode(com,INPUT);
  do{} while(digitalRead(com)==LOW);
  Serial.println("response");
  pinMode(com, OUTPUT);
  Serial.println("out");
  digitalWrite(com,LOW);
  Serial.println("low");
}

