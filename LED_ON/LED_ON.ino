int led = 3; // the pin the LED is connected to
int decreasing = 400;
int increasing = 150;
void setup() {
  pinMode(led, OUTPUT); // Declare the LED as an output
}

void loop() {
  digitalWrite(led, HIGH); // Turn the LED on
  delay(decreasing);
  digitalWrite(led, LOW);
  delay(increasing);
  decreasing = decreasing - 10;
}
