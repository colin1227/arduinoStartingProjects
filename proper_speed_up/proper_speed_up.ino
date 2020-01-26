const int left = 8;
const int right = 4;
boolean directionToGo = true;
int timeToWait = 1000;
void setup() {
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
}

void loop() {
   if (directionToGo == true) {
    Serial.println("right");
    digitalWrite(right, HIGH);
    delay(timeToWait);
    digitalWrite(right, LOW);
    directionToGo = false;
   } else {
    Serial.println("left");
    digitalWrite(left, HIGH);
    delay(timeToWait);
    digitalWrite(left, LOW);
    directionToGo = true;
    if (timeToWait == 600 ) {
      timeToWait = 75;
    } else if ( timeToWait > 649) {
      timeToWait -= 50;
    } else if ( timeToWait < 76 && timeToWait > 16) {
      timeToWait -= 3;
    }
   }

}