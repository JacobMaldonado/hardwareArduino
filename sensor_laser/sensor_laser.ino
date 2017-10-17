int laser = 9;
int botonPin = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(botonPin,INPUT);
  pinMode(laser,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(botonPin);
  if(val == HIGH)
    digitalWrite(laser, LOW);
  else
    digitalWrite(laser, HIGH);
  delay(100);
}
