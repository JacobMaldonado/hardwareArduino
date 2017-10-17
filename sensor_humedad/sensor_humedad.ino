#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

dht DHT;

int DHT11_PIN = 7;

void setup(){
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  int temperatura = DHT.temperature;
  int humedad = DHT.humidity;
  lcd.clear();
  lcd.setCursor(0,0);
  if(humedad >= 30 )
    lcd.print("Mira esa humedad");
  else
    lcd.print("holi");
  lcd.setCursor(0,1);
  if(temperatura >= 25){
    lcd.print("Me estoy quemando");
  }else{
    lcd.print("estoy bien :3");
  }
  lcd.setCursor(0,2);
  lcd.print("Temperature = ");
  lcd.print(DHT.temperature);
  lcd.setCursor(0,3);
  lcd.print("Humidity = ");
  lcd.print(DHT.humidity);
  delay(1000);
}

