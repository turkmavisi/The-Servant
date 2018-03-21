void WAIT1 (){
  do{} while(digitalRead(com)==LOW);
  pinMode(com,OUTPUT);
  digitalWrite(com,LOW);
}
