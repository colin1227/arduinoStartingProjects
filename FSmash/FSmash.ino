const int standard = 2;
const int jump = 3;
const int left = 4;
const int right = 5;
int timeToWait = 750;
void setup() {
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(standard, OUTPUT);
  pinMode(jump, OUTPUT);
}

void loop() {
  digitalWrite(standard, HIGH);
  digitalWrite(left, HIGH);
  delay(timeToWait);
  digitalWrite(standard, LOW);
  digitalWrite(left, LOW);
  delay(350);
}
