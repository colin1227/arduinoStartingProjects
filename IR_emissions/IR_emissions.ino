/*
* IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
* An IR LED must be connected to Arduino PWM pin 3.
* Version 0.1 July, 2009
* Copyright 2009 Ken Shirriff
* http://arcfn.com
*/
#include <IRremote.h>

IRsend irsend;

void setup()
{
 Serial.begin(9600);
}

void loop() { 
  Serial.print("Yea");
  irsend.sendNEC(1637937167,32); // powerup
  delay(7000);
}  
