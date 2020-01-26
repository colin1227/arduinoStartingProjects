#include <IRremote.h>
IRsend irsend;

const int buttonOut = 2;
const int buttonIn = 4;

const int IRPower = 9;
const int IRground = 7;
const int IR = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonOut, OUTPUT);
  pinMode(buttonIn, INPUT);
}

void loop() {
  digitalWrite(buttonOut, HIGH);
    if (digitalRead(buttonIn) == HIGH) {
      // emit
    Serial.print("aaaaa");
    Serial.println(" ");
    irsend.sendSony(61A0F00F, 16);
    }
}
