void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
}
void loop() {
   digitalWrite(A0, LOW);
   if (Serial.available() > 0) {
     Serial.write(Serial.read());   
     digitalWrite(A0, HIGH);
     delay(1000); 
   }
}
