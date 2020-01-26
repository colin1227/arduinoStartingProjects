const int mainPin = 9;
const int secondaryPin = 2;

void setup () {
  Serial.begin(9600);
  pinMode(mainPin, OUTPUT);
  pinMode(secondaryPin, OUTPUT);
  pinMode(A0, INPUT);
}

void loop () {
  digitalWrite(secondaryPin, HIGH);
  const int val = analogRead(A0);
  Serial.println(val);
  if (val > 512){
    digitalWrite(mainPin, HIGH);
  } else {
    digitalWrite(mainPin, LOW);
  }
}
