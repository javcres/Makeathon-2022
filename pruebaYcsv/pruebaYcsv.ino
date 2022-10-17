#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
#include <avr/sleep.h>
// #include "RTClib.h"
// #include <Wire.h>
// #include <TimeLib.h>
// #include <time.h>

// RTC_DS1307 RTC;
DHT dht(DHTPIN, DHTTYPE);

// time_t time_provider() {
//   return RTC.now().unixtime();
// }

// int nf = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  // Wire.begin();  //sets up the I2C
  // RTC.begin();   //initializes the I2C to the RTC
  // DateTime now = RTC.now();
}

void loop() {

  delay(5000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int luz = analogRead(A0);

  if (isnan(h) || isnan(t) || isnan(luz)) {
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
  Serial.println(luz);
}