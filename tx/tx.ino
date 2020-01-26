void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  if (digitalRead(A0) == HIGH) {
    digitalWrite(4, HIGH);
    Serial.write("awesome");
  } else {
    digitalWrite(4, LOW);
  }
}
