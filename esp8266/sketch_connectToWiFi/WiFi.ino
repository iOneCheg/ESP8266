void WiFiInit(){
  //Попытка подключения к точке доступа
  WiFi.mode(WIFI_STA);
  byte tries(10); //Количество попыток подключений к точке доступа(внешней)
  WiFi.begin(_ssid.c_str(),_password.c_str());

  while(--tries && WiFi.status()!=WL_CONNECTED)
  {
    Serial.print("");
    delay(1000);
  }
  if(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("");
    Serial.println("WiFi up AP");
    StartAPMode();
  }
  else{
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address:");
    Serial.println(WiFi.localIP());
  }
  
}

bool StartAPMode()
{
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP,apIP,IPAddress(255,255,255,0));
  WiFi.softAP(_ssidAP.c_str(),_passwordAP.c_str());
  return true;
}
