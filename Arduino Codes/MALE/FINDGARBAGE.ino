void FINDGARBAGE(){
  Serial.println("Find garbage");
  int d = 500; // delay
  turnside=0;
  while(!GARBAGEDETECT()){
    RANDOMTRAVEL();
    if(!digitalRead(FL)&&digitalRead(FR)){
      TURNRIGHT(d);
      STOP();
      turnside = 0;
    }
    if(digitalRead(FL)&&!digitalRead(FR)){
      TURNLEFT(d);
      STOP();
      turnside = 0;
    }    
    if(!digitalRead(FL)&&!digitalRead(FR)){
      GOBACK(2*d);
      STOP(); 
    }
  }
 // noInterrupts();//detachInterrupt(digitalPinToInterrupt(2)); 
  FINDCENTER();
  GARBAGEALIGN();
 // interrupts();//attachInterrupt(digitalPinToInterrupt(2), CNYCHECK, RISING);
  if(DISTANCELOW()>550){
    digitalWrite (resetf,HIGH);
    digitalWrite(resetf,LOW);
    resetFunc();
  }

}

