#include "SerialTransfer.h"

SerialTransfer myTransfer;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A7, OUTPUT);
  Serial.begin(115200);
  Serial1.begin(115200);
  myTransfer.begin(Serial1);
}

void loop()
{
  myTransfer.txBuff[2] = "hello";
  if (digitalRead(A0) == HIGH) {
    digitalWrite(A7, HIGH);
    myTransfer.sendData(3);
    delay(1000);
  } else { 
    digitalWrite(A7, LOW);
  }
}
