 
#include <Servo.h>
  
//Catch servos
  Servo cf;   
  Servo cb;   
   
//Lift servos 
  Servo lb;
  Servo lf;
  
//Platform servo  
  Servo p;

//Communication pin
  byte com = 13;


void setup() {

delay(100);

//Interrupt pin
  attachInterrupt(digitalPinToInterrupt(3), RST, HIGH);
//Catch servos
  cf.attach(5);   
  cb.attach(4);   
    //initializations
    cf.write(10);
    cb.write(25);
    
//Lift Servos  
  lb.attach(10);   
  lf.attach(11);  
    //Initializations
      lb.write(45);
      lf.write(130);
      
//Platform servo
  p.attach(12);    
    //Initialization
      p.write(20);

//Communication pin
  delay (100);
  pinMode (com, INPUT);
}

void(* resetFunc) (void) = 0;//declare reset function at address 0

void loop() {
WAIT1();
detachInterrupt(digitalPinToInterrupt(3)); 
  OPENCATCH();
WAIT2();
attachInterrupt(digitalPinToInterrupt(3), RST, HIGH);
WAIT1();
detachInterrupt(digitalPinToInterrupt(3)); 
  DOWNPLATFORM();
  CLOSECATCH();
  UPPLATFORM();
WAIT2();
attachInterrupt(digitalPinToInterrupt(3), RST, HIGH);
WAIT1();
detachInterrupt(digitalPinToInterrupt(3)); 
  UPLIFT();
  DROPPLATFORM();
  DOWNLIFT();
WAIT2();
attachInterrupt(digitalPinToInterrupt(3), RST, HIGH);
}

void RST (){
  resetFunc(); //call reset 
}

