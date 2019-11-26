/* ------------------------------------------------------------- */
/* GEOBOX.OSC.IoT - Smart Office Project                         */
/* GEOBOX AG - Smart Office mit IoT und Sensoren                 */
/* ------------------------------------------------------------- */
/* v19.1.1 - GEOBOX USO                                          */
/* v19.1.2 - GEOBOX USO - Move Settings to config File           */
/* ------------------------------------------------------------- */
/* for debug */
/*#define _DEBUG_*/
#include "config.c"
/* Include librarys */
#include <ESP8266WiFi.h>
#include "DHT.h"
/* Include thinger library */
#include <ThingerESP8266.h>
    
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);                

float Temperature;
float Humidity;
float MQ135Voltage; 
float MQ135Value;

// Intitalize Thinger Device
ThingerESP8266 thingDevice(THINGERUSERNAME, THINGERDEVICEID, THINGERDEVICECREDENTIAL);
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(DHTPin, INPUT);

  dht.begin();              

  /* printWiFiBeginConnect(WLANSSID); */
  Serial.println("Verbinde WiFi (thinger) SSID:");
  Serial.println(WLANSSID);

  thingDevice.add_wifi(WLANSSID, WLANPASSWORD);

  Serial.println("WiFi (thinger) ist verbunden...");

}
void loop() {
  thingDevice.handle();
  delay(2000);
  // Temperature and humidity
  Temperature = dht.readTemperature(); // Gets the values of the temperature
  Humidity = dht.readHumidity(); // Gets the values of the humidity 

  //Serial.println("Temperatur gelesen");
  Serial.println(String("Temperatur  : ") + String(Temperature, 2));

  //Serial.println("Feuchtigkeit gelesen");
  Serial.println(String("Feuchtigkeit : ") + String(Humidity,2));

  thingDevice["clima"] >> [](pson& out){
      out["temperature"] = Temperature;
      out["humidity"] = Humidity;
  };

  // Gas Value
  MQ135Value = analogRead(A0);
  MQ135Voltage = MQ135Value/1024*3.3; /* ppm CO2 */

  //Serial.println("MQ135 Value gelesen");
  Serial.println(String("MQ135 Wert : ") + String(MQ135Value, 2));

  //Serial.println("MQ135 Voltage berechnet");
  Serial.println(String("MQ135 Voltage : ") + String(MQ135Voltage,2));

  thingDevice["airquality"] >> [](pson& out){
      out["CO2"] = MQ135Voltage;
  };
}
