void RANDOMTRAVEL(){
  Serial.println("Random Travel");
  /*
    int turnside  
    0 gostraight chosen
    1 turnright chosen
    2 turnleft chosen
  */
   int d = 100; //delay
   randomSeed(millis());
   int a = random(0,250);
   switch(turnside){
    case 0 :
      if (a<50){
        GOSTRAIGHT(d);
        STOP();
        turnside=0;
      }
      else{
        if(a>150){
          TURNRIGHT(d);
          STOP();
          turnside = 1;  
        }
        else{
          TURNLEFT(d);
          STOP();
          turnside = 2;
        }
      }
    break;
    case 1 :
      if (a<50){
        GOSTRAIGHT(d);
        STOP();
        turnside=0;
      }
      else{
        TURNRIGHT(d);
        STOP();
        turnside = 1;             
      }
    break;
    case 2 :
      if (a<50){
        GOSTRAIGHT(d);
        STOP();
        turnside=0;
      }
      else{
        TURNLEFT(d);
        STOP();
        turnside = 2;             
      }  
    break;  
   }
}

