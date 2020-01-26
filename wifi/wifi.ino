#include <SPI.h>
#include <WiFiNINA.h>
const int off = 5;
const int on = 6;
char ssid[] = "Winterishere";                     // your network SSID (name)
char key[] = "addthrough";       // your network key
int keyIndex = 0;                                // your network key Index number

void connectToHomeNetwork() {
  WiFi.begin(ssid, keyIndex, key);
}

void checkHomeNetwork() {
  if (WiFi.status() != 3 ) {
    digitalWrite(off, HIGH);
    digitalWrite(on, LOW);
    Serial.print("Attempting to connect to WEP network, SSID: ");
    Serial.println(ssid);
    WiFi.begin(ssid, keyIndex, key);
 } else if (WiFi.status() == 3) {
   digitalWrite(off, LOW);
   digitalWrite(on, HIGH);
   Serial.print("connected");
   Serial.println(" ");
 }
}
void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  connectToHomeNetwork();
}

void loop() {
  checkHomeNetwork();
  delay(6000);
}
