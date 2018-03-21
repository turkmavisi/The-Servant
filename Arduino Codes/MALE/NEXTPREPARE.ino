void NEXTPREPARE(){
  Serial.println("Next prepare");
  int d = 400; // delay
  GOBACK(d);
  STOP();
  randomSeed(millis());
  int a = random(0,200);
  if(a>100){
    TURNRIGHT(d);
    STOP();
  }
  else{
    TURNLEFT(d);
    STOP();      
  }
}

