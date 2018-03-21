int DISTANCELOWAVG () {
  Serial.println("Distancelowavg");
  int a=0;
  for (int i=0; i<3; i++){
    a=a+DISTANCELOW(); 
  }
  a=a/3;
  Serial.println("AVG ");
  return a;
}

