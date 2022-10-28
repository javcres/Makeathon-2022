#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,20,4);  //

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD.
  lcd.print("Hola Mundo");
  delay(1000);
  lcd.clear();
}

String nombres[4] = {"Pene", "Pito", "Polla", "Tula"};
int cont = 0;

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.clear();
  lcd.setCursor(0, 0);
  // Escribimos el número de segundos trascurridos
  // lcd.print(millis()/1000);
  lcd.print(nombres[cont%4]);
  cont ++;
  delay(1500);
}

