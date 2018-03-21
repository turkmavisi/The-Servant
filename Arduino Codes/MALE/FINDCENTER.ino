void FINDCENTER () {
  Serial.println("Find center");
  long prev=0;
  long current=DISTANCELOWAVG();
  int d = 150; //delay
  if (current<350){
    switch (turnside){
      case 0:
       {
        TURNLEFT(d);
        STOP();
        prev = current;
        TURNRIGHT(2*d);
        STOP();
        current = DISTANCELOWAVG();
        TURNLEFT(d);
        STOP();
        long init = DISTANCELOWAVG();
        if(init<=prev && init<=current) return;
        if(current>prev){
          current=init;
          do{
            prev= current;
            TURNLEFT(d);
            STOP();
            current=DISTANCELOWAVG();
          }while(current<prev);
          TURNRIGHT(d);
          STOP();
        }
        else{
          current=init;
          do{
            prev= current;
            TURNRIGHT(d);
            STOP();
            current=DISTANCELOWAVG();
          }while(current<prev);
          TURNLEFT(d);
          STOP();
        }
        break;
       }
      case 1:
       {
         do{
           prev= current;
           TURNRIGHT(d);
           STOP();
           current=DISTANCELOWAVG();
        }while(current<prev);
        TURNLEFT(d);
        STOP();
        break;
       }
      case 2:
       {
         do{
           prev= current;
           TURNLEFT(d);
           STOP();
           current=DISTANCELOWAVG();
        }while(current<prev);
        TURNRIGHT(d);
        STOP();
        break;   
       }   
    }
  }

 
  if (current<550 && current>=350){
    int dfar = 100; //delay far
    switch (turnside){
      case 0:
       {
        TURNLEFT(dfar);
        prev = current;
        TURNRIGHT(2*dfar);
        STOP();
        current = DISTANCELOWAVG();
        TURNLEFT(dfar);
        STOP();
        long init = DISTANCELOWAVG();
        if(init<=prev && init<=current) return;
        if(current>prev){
          current=init;
          do{
            prev= current;
            TURNLEFT(dfar);
            STOP();
            current=DISTANCELOWAVG();
          }while(current<prev);
          TURNRIGHT(dfar);
          STOP();
        }
        else{
          current=init;
          do{
            prev= current;
            TURNRIGHT(dfar);
            STOP();
            current=DISTANCELOWAVG();
          }while(current<prev);
          TURNLEFT(dfar);
          STOP();
        }
        break;
       }
      case 1:
       {
         do{
           prev= current;
           TURNRIGHT(dfar);
           STOP();
           current=DISTANCELOWAVG();
        }while(current<prev);
        TURNLEFT(dfar);
        STOP();
        break;
       }
      case 2:
       {
         do{
           prev= current;
           TURNLEFT(dfar);
           STOP();
           current=DISTANCELOWAVG();
        }while(current<prev);
        TURNRIGHT(dfar);
        STOP();
        break;   
       }   
    }
  } 
}
