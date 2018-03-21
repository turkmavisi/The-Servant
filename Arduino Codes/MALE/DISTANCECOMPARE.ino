boolean DISTANCECOMPARE(){
  Serial.println("Distance compare");

  //each cm is 30
  //return 0 nothing
  //return 1 garbage detect

 byte garbage=0;    //Garbage detection
 if(DISTANCELOW()<500){     //it was 750 before
   for(int i=0 ; i<10 ; i++){
    long low = DISTANCELOW();
    long up = DISTANCEUP();
    if (abs(low-up) > 120) garbage++;
    }
  
   if (garbage > 6) return HIGH;
   else return LOW;
 }
}
