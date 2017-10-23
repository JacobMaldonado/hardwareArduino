void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Color(random(255),random(255),random(255));
  delay(500);
}

void Color(int R, int G, int B){
  analogWrite(9, R);
  analogWrite(10,G);
  analogWrite(11,B);  
}
