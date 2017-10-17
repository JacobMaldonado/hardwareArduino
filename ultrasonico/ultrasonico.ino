#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
const int led = 6;
const int pinecho = 11;
const int pintrigger = 12;
const int buzzerPin = 5; //piezo
unsigned int distancia, tiempo;

void setup() {
  Serial.begin(9600);
  //configuramos pines
  pinMode(led,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  lcd.init();
  lcd.backlight();
  digitalWrite(led,LOW);
}
 
void loop() {
  
  //se envia un disparo en el pin trigger
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  //el pulso dura al menos 10 microsegundos en estado alto
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  //medir tiempo es proporcional a la distancia
  tiempo = pulseIn(pinecho,HIGH);

  //el tiempo en recorrer 1 cm son 29 cm
  distancia = tiempo / 58;
  lcd.clear();
  
  lcd.setCursor(5,0);
  lcd.print("jacob");
  lcd.setCursor(3,1);
  lcd.print("la distancia es:");
  lcd.setCursor(5,2);
  lcd.print(distancia);
  
  if(distancia <15){
    lcd.setCursor(3,3);
    lcd.print("enendido");
    tone(buzzerPin,1000);
    digitalWrite(led,HIGH);
  }else{
    lcd.setCursor(3,3);
    lcd.print("apagado");
    noTone(buzzerPin);
    digitalWrite(led,LOW);
   }
  delay(1000);
}
