# define pirSensor 2

int reading;

void setup() {
  // put your setup code here, to run once:
  pinMode(pirSensor, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(pirSensor);

  if (reading == HIGH) {
    Serial.println("Motion");
  } else {
    
  }
  reading = LOW;
}
