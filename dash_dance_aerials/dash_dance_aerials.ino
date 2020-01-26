const int standard = A5;
const int jump = A4;
const int left = A3;
const int right = A2;

void dashDance() {
  for (int x = 0; x < 10; x++){
    digitalWrite(left, LOW);
    digitalWrite(right, HIGH);
    delay(67);
    digitalWrite(right, LOW);
    digitalWrite(left, HIGH);
    delay(67);
  }
  digitalWrite(left, LOW);
}

void leftNeutral() {
  digitalWrite(left, HIGH);
  delay(150);
  digitalWrite(jump, HIGH);
  delay(50);
  digitalWrite(jump, LOW);
  digitalWrite(left, LOW);
  digitalWrite(standard, HIGH);
  delay(100);
  digitalWrite(standard, LOW);
}

void rightNeutral() {
  digitalWrite(right, HIGH);
  delay(150);
  digitalWrite(jump, HIGH);
  delay(50);
  digitalWrite(jump, LOW);
  digitalWrite(right, LOW);
  digitalWrite(standard, HIGH);
  delay(100);
  digitalWrite(standard, LOW);
}

void backAirLeft() {
  digitalWrite(left, HIGH);
  delay(250);
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  delay(50);
  digitalWrite(right, LOW);
  digitalWrite(jump, HIGH);
  delay(50);
  digitalWrite(jump, LOW);
  digitalWrite(left, HIGH);
  digitalWrite(standard, HIGH);
  delay(100);
  digitalWrite(left, LOW);
  digitalWrite(standard, LOW);
}

void backAirRight() {
  digitalWrite(right, HIGH);
  delay(250);
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);
  delay(50);
  digitalWrite(left, LOW);
  digitalWrite(jump, HIGH);
  delay(50);
  digitalWrite(jump, LOW);
  digitalWrite(right, HIGH);
  digitalWrite(standard, HIGH);
  delay(100);
  digitalWrite(right, LOW);
  digitalWrite(standard, LOW);
}


void setup() {
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(standard, OUTPUT);
  pinMode(jump, OUTPUT);
}

void loop() {
 dashDance();
 backAirRight();
 dashDance();
 backAirLeft();

}
