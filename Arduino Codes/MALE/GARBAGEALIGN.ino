void GARBAGEALIGN(){
  Serial.println("Garbage allign");
  int d = 50; // delay
  if(DISTANCELOW()<300){
    while (DISTANCELOW()<300){
      GOBACK(d);
      STOP();
      if((!digitalRead(BL)||!digitalRead(BR))) {
        analogWrite (resetf,255);
        delay(10);
        analogWrite(resetf,0);
        resetFunc();
      }
    }
    STOP();
  }
}

