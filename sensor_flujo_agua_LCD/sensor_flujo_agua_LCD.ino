#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,20,4);

dht DHT;

int PinHumedad = 7;

volatile int NumPulsos; //variable para la cantidad de pulsos recibidos
int PinSensor = 2;    //Sensor conectado en el pin 2
float factor_conversion = 7.5; //para convertir de frecuencia a caudal



void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(PinSensor, INPUT);
  attachInterrupt(0, ContarPulsos, RISING); //(Interrupcion 0(Pin2),funcion,Flanco de subida)
}

void loop ()
{

  int chk = DHT.read11(PinHumedad);
  int temperatura = DHT.temperature;
  int humedad = DHT.humidity;
  float frecuencia = ObtenerFrecuencia(); //obtenemos la Frecuencia de los pulsos en Hz
  float caudal_L_m = frecuencia / factor_conversion; //calculamos el caudal en L/m
  float caudal_L_h = caudal_L_m * 60; //calculamos el caudal en L/h

  //-----Enviamos por el puerto serie---------------
  
  lcd.setCursor(0,0);
  lcd.print("Frecuencia: ");
  /*//lcd.print (frecuencia, 0);
  lcd.print ("HZ");
  lcd.setCursor(0,1);
  lcd.print ("Caudal: ");
  //lcd.print (caudal_L_m, 3);
  lcd.print (" L/m");
  lcd.setCursor(0,2);
  //lcd.print (caudal_L_h, 3);
  lcd.print ("L/h");
  lcd.setCursor(0,3);
  lcd.print ("H: ");
  lcd.print (humedad);
  lcd.print ("%T: ");
  lcd.print(temperatura);
  lcd.print("°");*/
  
}
//---Función que se ejecuta en interrupción---------------
void ContarPulsos ()
{
  NumPulsos++;  //incrementamos la variable de pulsos
}

//---Función para obtener frecuencia de los pulsos--------
int ObtenerFrecuencia()
{
  int frecuencia;
  NumPulsos = 0;   //Ponemos a 0 el número de pulsos
  interrupts();    //Habilitamos las interrupciones
  delay(1000);   //muestra de 1 segundo
  noInterrupts(); //Desabilitamos las interrupciones
  frecuencia = NumPulsos; //Hz(pulsos por segundo)
  return frecuencia;
}
