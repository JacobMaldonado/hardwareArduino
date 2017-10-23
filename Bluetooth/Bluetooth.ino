char junk;
String inputString = "";

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  if (Serial.available()) {
    while (Serial.available()) {
      char inChar = (char) Serial.read();
      inputString += inChar;


    }
    Serial.println(inputString);
    while (Serial.available() > 0) {
      junk = Serial.read();
    }
    if (inputString == "a") {
      Color(0,0,0);
    } else if (inputString == "b") {
      Color(255,0,0);
    } else if (inputString == "r")
      Color(0,255,0);
      else if (inputString == "g")
      Color(0,0,255);
    inputString = "";
  }
}

void Color(int R, int G, int B){
  analogWrite(9, R);
  analogWrite(10,G);
  analogWrite(11,B);  
}


