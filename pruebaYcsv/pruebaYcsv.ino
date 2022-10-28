#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
#include <SD.h>
#define SDPIN 4
#define FILE_NAME "datos.csv"
#include <avr/sleep.h>
// #include "RTClib.h"
// #include <Wire.h>
// #include <TimeLib.h>
// #include <time.h>

// RTC_DS1307 RTC;
DHT dht(DHTPIN, DHTTYPE);

File myFile;

// time_t time_provider() {
//   return RTC.now().unixtime();
// }

// int nf = 0;

void setup() {
  Serial.begin(9600);
  
  // Wire.begin();  //sets up the I2C
  // RTC.begin();   //initializes the I2C to the RTC
  // DateTime now = RTC.now();
  Serial.println("------------- INCIANDO SENSOR -------------");
  dht.begin();
  Serial.println("inicializacion exitosa");

  Serial.println("------------- INCIANDO SD -------------");
  if (!SD.begin(SDPIN)) {
    Serial.println("No se pudo inicializar SD");
    return;
  }
  Serial.println("inicializacion exitosa");
}

void loop() {

  delay(3000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int l = analogRead(A0);

  if (isnan(h) || isnan(t) || isnan(l)) {
    Serial.println("No se ha podido leer del sensor!");
    // nf ++;
    // if(nf == 10){
    //   sleep_mode();
    // }
    return;
  }

  // time_t time = now();
  // unsigned long time = (unsigned long) time_provider();

  Serial.print(t);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.println(l);

  myFile = SD.open(FILE_NAME, FILE_WRITE);//abrimos  el archivo 
  if (myFile) {
    Serial.println("Archivo abierto con exito");
  } else {
    Serial.println("Error al abrir el archivo");
  }

  myFile.print(t);
  myFile.print(",");
  myFile.print(h);
  myFile.print(",");
  myFile.println(l);

  myFile.close();
}