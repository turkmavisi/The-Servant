void DOWNLIFT (){
  for(int i=80;i>15;i--){
    lb.write(30+i);
    lf.write(148-8*i/7);
    delay(20);
  }
}
