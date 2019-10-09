/* ------------------------------------------------------------- */
/* GEOBOX.OSC.IoT - Smart Office Project                         */
/* GEOBOX AG - Smart Office mit IoT und Sensoren                 */
/* ------------------------------------------------------------- */
/* v19.1.1 - GEOBOX USO                                          */
/* ------------------------------------------------------------- */
/* for debug */
/*#define _DEBUG_*/

#include <ESP8266WiFi.h>
#include "DHT.h"

/* Set Server for using own thinger-server */
#define THINGER_SERVER "IPfromOwnServer" /* IP or Domain-Name for Server */
/* Include thinger library */
#include <ThingerESP8266.h>

/* SETTINGS for W-LAN Connection                                  */
/* -------------------------------------------------------------- */
#define WLANSSID "WLAN-SSID"
#define WLANPASSWORD "mySecretWlanWord"
/* SETTINGS thinger.io Plattform                                  */
/* -------------------------------------------------------------- */
#define THINGERUSERNAME "myThingerName"
#define THINGERDEVICEID "myThingerDeviceId"
#define THINGERDEVICECREDENTIAL "mySecretWord"

/* SETTINGS DHT Sensor                                            */
/* -------------------------------------------------------------- */
// DHT Sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
// PIN mit dem "Data" des DHT22 verbunden ist
uint8_t DHTPin = 4;             
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
