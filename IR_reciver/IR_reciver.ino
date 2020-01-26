#include <IRremote.h>
#include <IRremoteInt.h>
const int led = A4;
const int receiver = 3;
IRrecv irrecv(receiver);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led, OUTPUT);
  irrecv.blink13(false);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print(results.value, HEX);
    Serial.print(" ");
    Serial.print(results.decode_type);
    Serial.println(" ");
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
     digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    irrecv.resume();
  }
}
