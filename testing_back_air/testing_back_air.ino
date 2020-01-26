const int left = A5;
const int right = A4;
const int up = A3;
const int down = A2;
const int standard = A1;
const int jump = A0;
const int special = 10;
const int grab = 11;

void backAirLeft() {
  digitalWrite(left, HIGH);
  delay(350);
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  delay(85);
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

void setup() {
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(standard, OUTPUT);
  pinMode(jump, OUTPUT);
  
  digitalWrite(right, HIGH);
  delay(3000);
  digitalWrite(right, LOW);
  delay(100);
}

void loop() { 
  backAirLeft();
  delay(750);
}
