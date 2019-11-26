/* ------------------------------------------------------------- */
/* GEOBOX.OSC.IoT - Smart Office Project                         */
/* GEOBOX AG - Smart Office mit IoT und Sensoren                 */
/* ------------------------------------------------------------- */
/* v19.1.2 - GEOBOX USO                                          */
/* ------------------------------------------------------------- */

/* SETTINGS for W-LAN Connection                                 */
/* ------------------------------------------------------------- */
#define WLANSSID "WLAN-SSID"
#define WLANPASSWORD "mySecretWlanWord"

/* SETTINGS thinger.io Plattform                                  */
/* -------------------------------------------------------------- */
/* Set Server for using own thinger-server */
#define THINGER_SERVER "IPfromOwnServer" /* IP or Domain-Name for Server */
/* Set Login and Device credential */
#define THINGERUSERNAME "myThingerName"
#define THINGERDEVICEID "myThingerDeviceId"
#define THINGERDEVICECREDENTIAL "mySecretWord"

/* SETTINGS DHT Sensor                                            */
/* -------------------------------------------------------------- */
// DHT Sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
// PIN mit dem "Data" des DHT22 verbunden ist
#define DHTPin 4    
