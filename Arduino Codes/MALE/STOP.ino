void STOP (){
  digitalWrite (R0, LOW);
  digitalWrite (R1, LOW);
  digitalWrite (L0, LOW);
  digitalWrite (L1, LOW);
  
  analogWrite (pwmR, 0);
  analogWrite (pwmL, 0); 
}

