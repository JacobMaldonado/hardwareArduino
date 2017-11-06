#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

dht DHT;
int tiempo;
int distancia;
const int pinecho = 11;
const int pintrigger = 12;

int DHT11_PIN = 7;

volatile int NbTopsFan;
int Calc;
int hallsensor = 2;

void rpm ()
{
  NbTopsFan++;
}

void setup(){
  pinMode(hallsensor, INPUT);
  lcd.init();
  lcd.backlight();
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  
  attachInterrupt(0, rpm, RISING);
}

void loop()
{
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
  
  NbTopsFan = 0;
  sei();
  delay (1000);
  cli();
  Calc = (NbTopsFan * 60 / 5.5);
  
  sei();
  int chk = DHT.read11(DHT11_PIN);
  int temperatura = DHT.temperature;
  int humedad = DHT.humidity;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print (Calc, DEC);
  lcd.print (" Litros/min");
  lcd.setCursor(0,2);
  lcd.print(distancia);
  lcd.setCursor(0,3);
  lcd.print("T: ");
  lcd.print(DHT.temperature);
  lcd.print(" H: ");
  lcd.print(DHT.humidity);
  cli();
}
