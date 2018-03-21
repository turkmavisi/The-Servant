void FENCEDETECT(){
  Serial.println("Fence detect");
  randomSeed(millis());
  int a = random (200);
  long up; 
  int d = 75;  //delay
  if (a>100){
    if (DISTANCEUP()>1200){
      do{
        TURNRIGHT(d);
        STOP();
      }while(DISTANCEUP()>1200);
    }
    up = DISTANCEUP();
    do{
      TURNRIGHT(d);
      STOP();
    }while(DISTANCEUP()>=up);
    do{
      up = DISTANCEUP();
      if(up<200){
        do{
          GOBACK(d);
          STOP();
        }while(DISTANCEUP()<200);
      up=DISTANCEUP();
      }
      TURNRIGHT(d);
      STOP();
    }while(DISTANCEUP()<up);
    TURNLEFT(d);
    STOP();
  }
  
  else{
    if (DISTANCEUP()>1200){
      do{
        TURNLEFT(d);
        STOP();
      }while(DISTANCEUP()>1200);
    }
    up = DISTANCEUP();
    do{
      TURNLEFT(d);
      STOP();
    }while(DISTANCEUP()>=up);
    do{
      up = DISTANCEUP();
      if(up<200){
        do{
          GOBACK(d);
          STOP();
        }while(DISTANCEUP()<200);
         up=DISTANCEUP();
      }
      TURNLEFT(d);
      STOP();
    }while(DISTANCEUP()<up);
  }
}

