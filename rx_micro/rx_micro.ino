void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(2, OUTPUT);
}
void loop() {
   digitalWrite(2, LOW);
   if (Serial.available() > 0) {
     Serial1.write(Serial.read());    
   }
   if (Serial1.available() > 0) {
    Serial.write(Serial1.read());
    digitalWrite(2, HIGH);
    delay(1000);
   }
}
