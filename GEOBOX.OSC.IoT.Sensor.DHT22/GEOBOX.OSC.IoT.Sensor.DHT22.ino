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
}
