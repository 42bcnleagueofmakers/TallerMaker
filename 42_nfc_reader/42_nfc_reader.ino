#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

//Creamos el objeto NFC
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,4);  //

void setup() {
  //Inicializamos el puerto serie
  Serial.begin(9600);
  // Inicializar el LCD
  lcd.init();
  //Encender la luz de fondo.
  lcd.backlight();
  // Escribimos el Mensaje en el LCD.
  lcd.setCursor(0, 0);
  lcd.print("42Barcelona - Makers");
  //Inicializamos el lector  
  nfc.begin();
}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la linea 3
  Serial.println("\nScan a NFC tag >>\n");
  lcd.setCursor(0, 1);
  lcd.print("Scan a NFC tag >>");
  if (nfc.tagPresent())
  {
    NfcTag tag = nfc.read();
    tag.print();
    lcd.setCursor(0, 2);
    lcd.print(tag.getTagType());
    lcd.setCursor(0, 3);
    lcd.print(tag.getUidString());    
  }
  delay(1000);
   // Escribimos el número de segundos trascurridos
  //lcd.print(millis()/1000);
  //lcd.print(" Segundos");
  delay(100);
}