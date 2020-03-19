#define light A0  
#define light2 A1
#include <AltSoftSerial.h>
int l = 0;
bool go = false;
int c = 0;
AltSoftSerial altSerial;

void fizzbuzz(int c) {
  if (c % 2 == 0 && c % 3) {
    digitalWrite(light, HIGH);
    digitalWrite(light2, HIGH);
  } else if (c % 2 == 0) {
    digitalWrite(light, HIGH);
    digitalWrite(light2, LOW);
  } else if (c % 3 == 0) {
    digitalWrite(light, LOW);
    digitalWrite(light2, HIGH);
  } else {
    digitalWrite(light, LOW);
    digitalWrite(light2, LOW);
  }
  if (l <= 380) {
    l = l + 5;
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("AltSoftSerial Test Begin");
  altSerial.begin(9600);
  altSerial.println("Hello World");
}

void loop() {
  if (altSerial.available()) {
    c = altSerial.read();
    Serial.println(c - 0);
    go = true;
  }
  if (go){
    fizzbuzz(c);
    delay(400 - l);

    Serial.println(c - 0);
    c = c + 1;
  }
}
