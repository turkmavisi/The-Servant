boolean GARBAGEDETECT(){
  Serial.println("Garbage detect");
  int d = 100; //delay
  if(DISTANCECOMPARE()){
    //noInterrupts();//detachInterrupt(digitalPinToInterrupt(2));
    if(turnside==1){
      if (DISTANCELOW()<350) {TURNRIGHT(2*d);}
      else {TURNRIGHT(d);}
      STOP();
    }
    if(turnside==2){
      if (DISTANCELOW()<350) {TURNLEFT(2*d);}
      else {TURNLEFT(d);}
      STOP();
    }
    if(DISTANCELOW()<100){
      GOBACK(3*d/2);
      STOP();
    }
    else{
      GOSLOW(3*d/2);
      STOP();
    }
    // interrupts();//attachInterrupt(digitalPinToInterrupt(2), CNYCHECK, RISING);
     if(DISTANCECOMPARE()) return HIGH;
     else return LOW;
  }
  else return LOW;
}

