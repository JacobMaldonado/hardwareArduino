#include <dht.h>

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
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  Serial.begin(9600);
  
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
  Serial.print (Calc, DEC);
  Serial.print (" Litros/min     ");
  Serial.print(distancia);
  Serial.print("cm");
  Serial.print("    T: ");
  Serial.print(DHT.temperature);
  Serial.println("     H: ");
  Serial.print(DHT.humidity);
  cli();
}
