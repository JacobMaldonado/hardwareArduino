//KY018 Photo resistor module
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int sensorPin = A0; // Entrada del potenciometro
int ledPin = 13; // Pin del led demostrativo
int sensorValue = 0; // Variable en que se almacenan los datos del sensor
void setup() {
  pinMode(ledPin, OUTPUT);
  lcd.init();
  lcd.backlight();
}
void loop() {
  lcd.clear();
  sensorValue = analogRead(sensorPin);
  if (sensorValue > 50)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
  lcd.setCursor(0, 0);
  lcd.print("la luz es :");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue, DEC);


  delay(500);


}
