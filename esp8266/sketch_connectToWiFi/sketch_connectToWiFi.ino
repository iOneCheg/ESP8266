

#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

IPAddress apIP(192,168,1,30);
ESP8266WebServer HTTP(80);

String _ssid = "Keenetic-5389";
String _password = "Fb6ciSeB";
String _ssidAP = "WiFi_Esp8266";
String _passwordAP = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Start connecting to WiFi");

  WiFiInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  HTTP.handleClient();
  delay(1);
}
