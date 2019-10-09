void printMessageToSerialPrinter(char message, bool newLine = true) {
  if (newLine) {
    Serial.println(message);
  }
  else {
    Serial.print(message);
  }
}


void printMessage(char &message) {
  printMessageToSerialPrinter(message);
}

void printWiFiBeginConnect(char wlanssid) {
  printMessageToSerialPrinter('Verbinde mit WiFi: ' + wlanssid);
}

void printWiFiConnected(char &ipAddress) {
  printMessageToSerialPrinter('Verbunden mit folgender IP-Adresse: ' + ipAddress);
}

void printTemperature(float &temperature) {
  printMessageToSerialPrinter('Temperatur  : ' + temperature);
}

void printHumididty(float &humidity) {
  printMessageToSerialPrinter('Feuchtigkeit : ' + humidity);
}

void printSpaceLine() {
  Serial.println("");
}
