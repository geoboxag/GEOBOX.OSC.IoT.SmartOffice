/* ------------------------------------------------------------- */
/* GEOBOX.OSC.IoT - Smart Office Project                         */
/* GEOBOX AG - Smart Office mit IoT und Sensoren                 */
/* ------------------------------------------------------------- */
/* v19.1.1 - GEOBOX KLA                                          */
/* ------------------------------------------------------------- */
/* for debug */
/*#define _DEBUG_*/
#include "config.c"
/* Include librarys */
#include <ESP8266WiFi.h>
#include <Wire.h>
/* Include thinger library */
#include <ThingerESP8266.h>


float Temperature;
float Humidity;

// Intitalize Thinger Device
ThingerESP8266 thingDevice(THINGERUSERNAME, THINGERDEVICEID, THINGERDEVICECREDENTIAL);
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  Wire.begin();
  Wire.beginTransmission(SI7021ADDR);
  Wire.endTransmission();

  /* printWiFiBeginConnect(WLANSSID); */
  Serial.println("Verbinde WiFi (thinger) SSID:");
  Serial.println(WLANSSID);

  thingDevice.add_wifi(WLANSSID, WLANPASSWORD);

  Serial.println("WiFi (thinger) ist verbunden...");

}
void loop() {

  thingDevice.handle();

  unsigned int data[2];
 
  Wire.beginTransmission(SI7021ADDR);
  //Send humidity measurement command
  Wire.write(0xF5);
  Wire.endTransmission();
  delay(500);
 
  // Request 2 bytes of data
  Wire.requestFrom(SI7021ADDR, 2);
  // Read 2 bytes of data to get humidity
  if(Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
 
  // Convert the data
  float hum  = ((data[0] * 256.0) + data[1]);
  Humidity = ((125 * hum) / 65536.0) - 6;
 
  Wire.beginTransmission(SI7021ADDR);
  // Send temperature measurement command
  Wire.write(0xF3);
  Wire.endTransmission();
  delay(500);
 
  // Request 2 bytes of data
  Wire.requestFrom(SI7021ADDR, 2);
 
  // Read 2 bytes of data for temperature
  if(Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
 
  // Convert the data to Celsius
  float temp  = ((data[0] * 256.0) + data[1]);
  Temperature = ((175.72 * temp) / 65536.0) - 46.85;

  //Serial.println("Temperatur gelesen");
  Serial.println(String("Temperatur  : ") + String(Temperature, 4));

  //Serial.println("Feuchtigkeit gelesen");
  Serial.println(String("Feuchtigkeit : ") + String(Humidity,4));

  thingDevice["clima"] >> [](pson& out){
      out["temperature"] = Temperature;
      out["humidity"] = Humidity;
  };
  
}
