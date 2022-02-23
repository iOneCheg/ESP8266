void Http_Init(void)
{
  HTTP.onNotFound(handleNotFound);
  HTTP.on("/", handleRoot);
  HTTP.on("/restart", handleRestart);

  HTTP.begin();
}

void handleNotFound(){
  String message = "File not found\n\n";
  message += "URI: ";
  message += HTTP.uri();
  message += "\nMethod: ";
  message += (HTTP.method() == HTTP_GET)? "GET":"POST";
  message +="\nArguments: ";
  message +=HTTP.args();
  message += "\n";
  for(uint8_t i=0;i<HTTP.args();i++){
    message+= " "+ HTTP.argName(i) + ": "+HTTP.arg(i)+"\n";
  }
  HTTP.send(404,"text/plain",message);
}

void handleRoot(){
  HTTP.send(200, "text/plain","hello from esp8266");
}

void handleRestart(){
  String restart = HTTP.arg("device");
  if(restart == "ok") ESP.restart();
  HTTP.send(200, "text/plain", "OK");
}
