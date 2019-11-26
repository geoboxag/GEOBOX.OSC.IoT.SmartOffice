/* ------------------------------------------------------------- */
/* GEOBOX.OSC.IoT - Smart Office Project                         */
/* GEOBOX AG - Smart Office mit IoT und Sensoren                 */
/* ------------------------------------------------------------- */
/* v19.1.1 - GEOBOX SME                                          */
/* ------------------------------------------------------------- */
/* for debug */
/*#define _DEBUG_*/
#include "config.c"
/* Include librarys */
#include <OneWire.h>
#include <DallasTemperature.h>
/* Include thinger library */
#include <ThingerESP8266.h>
    
// Initialize sensor.
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);             

float Temperature;

// Intitalize Thinger Device
ThingerESP8266 thingDevice(THINGERUSERNAME, THINGERDEVICEID, THINGERDEVICECREDENTIAL);
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  sensors.begin(); //Starten der Kommunikation mit dem Sensor             

  /* printWiFiBeginConnect(WLANSSID); */
  Serial.println("Verbinde WiFi (thinger) SSID:");
  Serial.println(WLANSSID);

  thingDevice.add_wifi(WLANSSID, WLANPASSWORD);

  Serial.println("WiFi (thinger) ist verbunden...");

}
void loop() {
  thingDevice.handle();
  delay(2000);

  sensors.requestTemperatures();
  
  Temperature = sensors.getTempCByIndex(0); // Gets the values of the temperature

  //Serial.println("Temperatur gelesen");
  Serial.println(String("Temperatur  : ") + String(Temperature, 2));

  thingDevice["clima"] >> [](pson& out){
      out["temperature"] = Temperature;
  };
}
