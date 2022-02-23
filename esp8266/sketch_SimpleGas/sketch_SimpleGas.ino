
void setup() {
  Serial.begin(115200);
  Serial.println("MQ-9 Test");
  pinMode(A0,INPUT);
}

void loop() {

  Serial.println("A0="+String(analogRead(A0)));
  delay(500);
}
