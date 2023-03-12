#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //

void setup() {
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD.
  lcd.print("42Barcelona");
  lcd.setCursor(0, 2);
  lcd.print("League Of Makers");

}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 3);
   // Escribimos el número de segundos trascurridos
  //lcd.print(millis()/1000);
  //lcd.print(" Segundos");
  delay(100);
}