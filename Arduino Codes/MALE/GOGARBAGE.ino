void GOGARBAGE(){
  Serial.println("Go garbage");
  int d = 30; //delay
  int a = DISTANCELOW();
  if((a>200) && (a<550)){
    while(a>200 && a<550){
       GOSLOW(2*d);      //was gostraight
       STOP();
       a = DISTANCELOW();
    }
  }
  if((a>125) && (a<=200)){
    while(a>100 && a<=200){
      GOSLOW(d);
      STOP();
      a = DISTANCELOW();
    }
    Serial.println("closest ");
    Serial.print(a);
  }
  if (a>150){
    GOBACK(10*d);
    STOP();
    digitalWrite (resetf,HIGH);
    digitalWrite (resetf,LOW);
    Serial.println("resetf");
    resetFunc(); //call reset 
  }
}

