int a = 12;
int b = 10;
int c = 13;
int increment = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(b, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(b) == HIGH) {
    digitalWrite(c, HIGH);
  } else {
    digitalWrite(c, LOW);
  }
}
