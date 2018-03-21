void FENCEALIGN(){
  Serial.println("fence align");

 int d = 20; //delay
 // noInterrupts();//detachInterrupt(digitalPinToInterrupt(2)); 

  while (digitalRead(FL) && digitalRead(FR)) {
    GOSLOW(d);
    STOP();
  }
  do{
    if(digitalRead(FL)&&digitalRead(FR)){
      GOSLOW(d);
      STOP();
    }
    if(!digitalRead(FL)&&digitalRead(FR)){   //SLOWTURNLEFT
      do{
        digitalWrite (R0, LOW);
        digitalWrite (R1, HIGH);
        digitalWrite (L0,HIGH);
        digitalWrite (L1, LOW);
        analogWrite (pwmR, 200);
        analogWrite (pwmL, 200); 
        delay(d);
        STOP();
      }while(digitalRead(FR));
    }
    if(!digitalRead(FR)&&digitalRead(FL)){   //SLOWTURNRIGHT
      do{
        digitalWrite (L0, LOW);
        digitalWrite (L1, HIGH);
        digitalWrite (R0,HIGH);
        digitalWrite (R1, LOW);     
        analogWrite (pwmR, 200);
        analogWrite (pwmL, 200); 
        delay(d);
        STOP();
      }while(digitalRead(FL));
    } 
  } while (digitalRead(FL)||digitalRead(FR));
  GOBACK(10*d);
  STOP();
  //interrupts();//attachInterrupt(digitalPinToInterrupt(2), CNYCHECK, RISING);
}

