#include <SoftwareSerial.h>

//Sensor pins
  byte trigPinLow =  7;   //Lower sendor trig pin
  byte echoPinLow = 8; 
  byte trigPinUp = 3;     //Upper sensor trig pin
  byte echoPinUp = 4;
 
//Motor pins
  //Directions (Straight movement R0&L0=0 R1&L1=1)
    int L0 = A0;
    int L1 = A1;
    int R0 = A2;
    int R1 = A3;
  //PWM
    byte pwmL = 5;
    byte pwmR = 6;
    
//Previous turn (0 no prev turn 1 right 2 left)
byte turnside = 0;

//CNY70 pins
  byte FL = 9;
  byte BL = 10;
  byte BR = 11;
  byte FR = 12;

//Communication pin
  byte com = 13;
  
//Reset pins
  int resetf = A5;
  
void setup() {

//Serial port
Serial.begin (9600);
Serial.println("Start");

//Interrupt pin
  //attachInterrupt(digitalPinToInterrupt(2), CNYCHECK, RISING);

//Sensor pins
  pinMode(trigPinLow, OUTPUT);
  pinMode(echoPinLow, INPUT);
  pinMode(trigPinUp, OUTPUT);
  pinMode(echoPinUp, INPUT);

//Motor pins
  //Directions
    pinMode (L0, OUTPUT);
    pinMode (L1, OUTPUT);
    pinMode (R0, OUTPUT);
    pinMode (R1, OUTPUT);
  //PWM
    pinMode (pwmL, OUTPUT);
    pinMode (pwmR, OUTPUT);
  //Initializations
    analogWrite (pwmR, 0);
    analogWrite (pwmL, 0); 
    
//CNY70 pins
  pinMode (FL, INPUT);
  pinMode (BL, INPUT);
  pinMode (BR, INPUT);
  pinMode (BL, INPUT);

//Communication pin
  pinMode (com, OUTPUT);
  digitalWrite (com, LOW);

//Reset pins
  pinMode (resetf, OUTPUT);
  digitalWrite(resetf,LOW);

}

void(* resetFunc) (void) = 0;//declare reset function at address 0

void loop(){
Serial.println("Restart");
FINDGARBAGE();
WAIT();         // open catch
GOGARBAGE();
WAIT();         // close catch
Serial.println("catch closed");
FINDFENCE();
WAIT();         // drop
Serial.println("garbage dropped");
NEXTPREPARE();
}

/*void CNYCHECK () {
  noInterrupts();
  delay(5000);
  Serial.println("interrupt");
  STOP();
  int cnyval = (!digitalRead(FL))+2*(!digitalRead(BL))+4*(!digitalRead(BR))+8*(!digitalRead(FR));
  randomSeed(millis());
  int wai = random(200,400); 
  switch(cnyval){
    
    //Front cases
    case 1 :
      TURNRIGHT();
      delay(1000);
      STOP();
      break;
    case 8 :
      TURNLEFT();
      delay(wai);
      STOP();
      break;
    case 9 :
      GOBACK();
      delay(300);
      if(wai>300) TURNRIGHT();
      else TURNLEFT();
      delay(wai);
      STOP();
      break;
      
    //Back cases
    case 2 :
      GOSTRAIGHT();
      delay(100);
      TURNRIGHT();
      delay(wai);
      GOSTRAIGHT();
      delay(300);
      STOP();
      break;
    case 4:
      GOSTRAIGHT();
      delay(100);
      TURNLEFT();
      delay(wai);
      GOSTRAIGHT();
      delay(300);
      STOP();
      break;
    case 6:
      GOSTRAIGHT();
      delay(100);
      if(wai>300) TURNRIGHT();
      else TURNLEFT();
      delay(wai);
      GOSTRAIGHT();
      delay(300);
      STOP();
      break;
  }  
  interrupts();
}
*/
