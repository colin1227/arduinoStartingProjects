#include <Wire.h> 

int T = 2; // INPUT PIN

int count = 0;

const String dot = ".";
const String detected = "Detected";

void setup() {
  Serial.println("Start module");
  pinMode(T, INPUT);

  delay(1000);
  Serial.println(" ");
}

void loop() {
  if(count == 0) {
    Serial.println("S026:KY-033 Tracking");
    Serial.println(" ");
  }
  if(count >= 20) {
    count = 0;
  }

  if (LOW == digitalRead(T)) {

    Serial.println(detected);
    count++;
  } else {

    Serial.println(dot);
    count++;

  }

  delay(100);

}
