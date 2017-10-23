#include<dht.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

dht DHT;

int lol = 7;

void setup ()

{
  lcd.init();
  lcd.backlight();
}

void loop ()

{
    int chk = DHT.read11(lol);
  int temperatura = DHT.temperature;
  int humedad = DHT.humidity;

  lcd.clear();
  lcd.setCursor(0,0);
  
  if(humedad>=30){
    lcd.print("me moje");
    }
  delay(400);
  }



