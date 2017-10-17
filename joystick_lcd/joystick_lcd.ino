#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int boton = 4;// Controla el salto por movimiento
int Eje_X = A1 ;
int Eje_Y = A2 ;
int posicion = 0;
int altura = 0;
int botonValor = 1;
boolean pintar = false;
int pantalla[4][20];

void setup()
{

  pinMode( boton, INPUT_PULLUP) ;

  lcd.init();
  lcd.backlight();
}

void loop()
{

  int p = analogRead(A1);
  int y = analogRead(A2);

  lcd.setCursor(posicion, altura);
  
  if (!pintar) 
    lcd.print(" ");
  else
    lcd.print("#");
  posicion = movimientoX(p, posicion);
  altura = movimientoY(y, altura);

  if (digitalRead(boton) == 0) {
    if (pintar)
      pintar = false;
    else
      pintar = true;
  }

  if (posicion >= 20)
    posicion = 19 ;
  else if (posicion < 0)
    posicion = 0;
  if (altura < 0)
    altura = 0;
  else if (altura > 3)
    altura = 3;

  if (pintar) {
    pantalla[altura][posicion] = 1;
  }

  lcd.setCursor(posicion, altura);
  lcd.print("|");
  // Aumentamos el angulo           // Y este es el que mueve el servo
  delay (200);                       // Este delay regula la velocidad del movimiento


}

int movimientoX(int p, int posicion) {
  if ( p < 400 ) {
    //lcd.clear();
    posicion++;// Si la lectura es menor de 400

  }
  else if (p > 600) {
    //lcd.clear();
    posicion --;// Si mayor de 600
  }
  return posicion;
}

int movimientoY(int y, int altura) {
  if (y < 400 ) {
    //lcd.clear();
    altura ++;
  } else if ( y > 600) {
    //lcd.clear();
    altura --;
  }
  return altura;
}
