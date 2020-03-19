#include <SoftwareSerial.h>


SoftwareSerial mySerial(5, 6); // RX, TX

#define in 3;



void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(3) == HIGH) {
    mySerial.write(12);
    Serial.write("YeaH!");
    delay(500);
  }
}
