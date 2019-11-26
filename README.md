# GEOBOX AG - GEOBOX.OSC.IoT.SmartOffice
Smart Office Projekt - eigene IoT Plattform mit diversen Sensor-Daten.

# Beschrieb
Diverse Sensoren liefern Daten in die IoT Plattform:
- Überwachung des Raum Klima mit Temprratur und Luftfeuchtigkeit
- Überwachung des Server Rack mit Tempreatur
- Überwacheng der Aussentemperatur
- Messen der Luftqualität
- ....

# IoT Plattform
Als Plattform wird der Server von thinger.io eingesetzt.
HINWEIS: für einen Test mit zwei Sensoren kann ein Account auf der Webseite erstellt werden

# Sensoren
Für das Messen der Daten kommen verschiedene Sensorem mit dem WeMos D1 mini (ESP8266 NodeMcu Lua Board) verwendet.


## GEOBOX Temperature Sensor DHT22
### Bauteile
- WeMos D1 mini (ESP8266 NodeMcu Lua Board)
- DHT22 Temperatur und Luftfeuchtigkeitssensor

### Code Projekt
- GEOBOX.OSC.IoT.Sensor.DHT22

### Verkabelung
| WeMos | DHT22 |
|-------|-----|
| 3V    | VCC |
| G     | GND |
| D4    | DOUT |