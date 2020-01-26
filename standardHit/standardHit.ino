const int left = 3;
const int right = 4;
boolean direction = false;
void setup() {
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
}

void loop() {
  if (direction == false) {
    digitalWrite(left, HIGH);
    delay(1000);
    digitalWrite(left, LOW);
    delay(1000);
    direction = true;
  } else {
    digitalWrite(right, HIGH);
    delay(1000);
    digitalWrite(right, LOW);
    delay(1000);
    direction = false;
  }
  
}
