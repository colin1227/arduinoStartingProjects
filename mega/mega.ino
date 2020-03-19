#include <IRremote.h>

IRsend irsend;

const int light = 7;
const int left = 28;
const int right = A4;
const int up = A5;
const int down = A3;
const int Z = 47;
const int start = 44;
const int A = 49;
const int B = 48;
const int Y = 46;
const int LR = 45;
const int LTilt = 43;
const int RTilt = 42;
int input;

void button40(int direct, int wait = 40) {
   digitalWrite(direct, HIGH);
   delay(wait);
   digitalWrite(direct, LOW);
   digitalWrite(direct, LOW);
   digitalWrite(direct, LOW);
   delay(40);
}

void playState() {
  button40(A);
  button40(A);
  button40(B);
  input = 0;
}

void test() {
  Serial.println("test");
  input = 0;
}

void debug() {
  Serial.println("debug");
  button40(A, 25);
  input = 0;
}

void rewind30() {
  button40(up);
  button40(up);
  button40(left);
  button40(left);
  button40(left);
  button40(A);
  input = 0;
}

void fastForward30() {
  button40(up);
  button40(up);
  button40(right);
  button40(right);
  button40(right);
  button40(A);
  input = 0;
}

void goBack() {
  button40(B);
  input = 0;
}

void powerTV() {
  irsend.sendNEC(1637937167,32);
  input = 0;
}

void volumeUp() {
  irsend.sendNEC(1637888207,32);
  input = 0;
}

void volumeDown() {
  irsend.sendNEC(1637920847,32);
  input = 0;
}

void mute() {
  irsend.sendNEC(1637904527, 32);
  input = 0;
}

 int readSerial(int val) {
  Serial.end();
  delay(15);
  Serial.begin(9600);
  return val;
 }

void setup() {
  
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(light, OUTPUT);
  pinMode(start, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(Z, OUTPUT);
  pinMode(LR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial2.available()) {
     input = Serial2.read();
     Serial.println(input);
   }
   switch (input) {
    case 1:
      playState();
      break;
    case 2:
      playState();
      break;
    case 4:
      goBack();
      break;
    case 10:
      powerTV();
      digitalWrite(light, HIGH);
      delay(1200);
      digitalWrite(light, LOW);
      break;
    case 30:
      rewind30();
      break;
    case 60:
      fastForward30();
      break;
    case 42:
      test();
      break;
    case 77:
      debug();
      break;
    default:
      input = 0;
      break;
   }
}
