#include <IRremote.h>
#include <IRremoteInt.h>
const int led = A4;
const int receiver = 11;
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
    Serial.print(results.value);
    Serial.print(" ");
    Serial.print(results.decode_type);
    Serial.println(" ");
    delay(100);
    irrecv.resume();
  }
}
