#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,20,4);

int xPin = A1;
int yPin = A2;
int buttonPin = 4;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  // inicializar las comunicaciones en serie a 9600 bps:
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  lcd.init();
  lcd.backlight();
  //activar resistencia pull-up en el pin pulsador 
  pinMode(buttonPin, INPUT_PULLUP); 
  
  // Para las versiones anteriores a 1.0.1 Arduino 
  // pinMode (buttonPin, INPUT); 
  // digitalWrite (buttonPin, HIGH);
  lcd.setCursor(5,0);
  lcd.print("DATOS");
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  lcd.setCursor(0,1);
  lcd.print("X: ");
  lcd.setCursor(3,1);
  lcd.print(xPosition);
  lcd.setCursor(0,2);
  lcd.print("Y: " );
  lcd.setCursor(3,2);
  lcd.print(yPosition);
  lcd.setCursor(0,3);
  lcd.print(buttonState );

  delay(100); // añadir un poco de retraso entre lecturas
  lcd.clear();
}

