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


## GEOBOX DHT22 - Temperatur und Luftfeuchtigkeit
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

## GEOBOX DS18B20 - Temperatur
### Bauteile
- WeMos D1 mini (ESP8266 NodeMcu Lua Board)
- DS18B20 Temperatursensor wasserdicht

### Code Projekt
- GEOBOX.OSC.IoT.Sensor.DS18B20

### Verkabelung
| WeMos | DS18B20 |
|-------|-----|
| 3V    | VCC |
| G     | GND |
| D4    | DOUT |


# Bestellliste
Alle Bauteile können im Online-Shop bastelgarage.ch bestellt werden:
| Bauteil | Link |
|---------|------|
| WeMos   | https://www.bastelgarage.ch/esp8266-esp32/esp-boards/wemos-d1-mini-esp8266-nodemcu-lua-board |
| DHT22   | https://www.bastelgarage.ch/bauteile/sensoren/temperatur/dht22-temperatur-und-luftfeuchtigkeitssensor-steckbar |
| Si7021  | https://www.bastelgarage.ch/bauteile/sensoren/temperatur/si7021-hochgenauer-temperatur-und-luftfeuchtigkeitssensor-mit-i2c |
| DS18B20 | https://www.bastelgarage.ch/bauteile/sensoren/1m-temperatursensor-wasserdicht-ds18b20-geschirmt |
| MQ-135  | https://www.bastelgarage.ch/bauteile/sensoren/co2-gas-luftqualitat/mq-135-gas-sensor-luftqualitat |
| CCS811  | https://www.bastelgarage.ch/bauteile/sensoren/co2-gas-luftqualitat/sparkfun-ccs811-co2-air-quality-sensor |
