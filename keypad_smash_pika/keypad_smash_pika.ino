#include <Keypad.h>

const int left = 28;
const int right = 52;
const int up = 51;
const int down = 50;
const int Z = 47;
const int start = 44;
const int A = 49;
const int B = 48;
const int Y = 46;
const int LR = 45;
const int LTilt = 43;
const int RTilt = 42;
char lastKey = "";
const int timeToWait = 500;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void button40(int direct, int wait = 40) {
   digitalWrite(direct, HIGH);
   delay(wait);
   digitalWrite(direct, LOW);
   digitalWrite(direct, LOW);
   digitalWrite(direct, LOW);
   delay(40);
}

void reset() {
  delay(100);
  digitalWrite(LR, HIGH);
  delay(400);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(LR, LOW);
  digitalWrite(A, LOW); 
  delay(400);
}

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

void grabDownThrow() {
  digitalWrite(Z, HIGH);
  delay(200);
  digitalWrite(Z, LOW);
  delay(200);
  digitalWrite(down, HIGH);
  delay(50);
  digitalWrite(down, LOW);
  delay(200);

}

void Uair(int drift = false) {
  digitalWrite(Y, HIGH);
  delay(50);
  if (drift) {
    digitalWrite(drift, HIGH);
    delay(30);
    digitalWrite(drift, LOW);
  } 
  digitalWrite(up, HIGH);
  digitalWrite(A, HIGH);
  delay(50);
  digitalWrite(Y, LOW);
  digitalWrite(up, LOW);
  delay(75);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}

void Nair(int drift = false) {
  button40(Y);
  if (drift) {
    digitalWrite(drift, HIGH);
    delay(40);
  }
  delay(125);
  if (drift) {
    digitalWrite(drift, LOW);
    digitalWrite(drift, LOW);
    digitalWrite(drift, LOW);

  }
  digitalWrite(A, HIGH);
  delay(400);
  digitalWrite(down, HIGH);
  if (drift) {
    digitalWrite(drift, HIGH);
  }
  delay(100);
  digitalWrite(Y, LOW);
  digitalWrite(A, LOW);
  delay(100);
  digitalWrite(drift, LOW);
  digitalWrite(down, LOW);
  delay(100);
}


void NairLeft(int wait = 150) {
  digitalWrite(left, HIGH);
  delay(wait);
  digitalWrite(Y, HIGH);
  delay(50);
  digitalWrite(Y, LOW);
  digitalWrite(left, LOW);
  digitalWrite(A, HIGH);
  delay(700);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}

void NairRight(int wait = 150) {
  digitalWrite(right, HIGH);
  delay(wait);
  digitalWrite(Y, HIGH);
  delay(50);
  digitalWrite(Y, LOW);
  digitalWrite(right, LOW);
  digitalWrite(A, HIGH);
  delay(700);
  digitalWrite(left, HIGH);
  delay(0);
  digitalWrite(left, LOW);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}


void Bair(int backward = left, int forward = right) {
  button40(Y);
  digitalWrite(forward, HIGH);
  delay(125);
  digitalWrite(forward, LOW);
  digitalWrite(backward, HIGH);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(backward, LOW);
  delay(300);
  digitalWrite(down, HIGH);
  delay(100);
  digitalWrite(Y, LOW);
  digitalWrite(A, LOW);
  delay(100);
  digitalWrite(down, LOW);
  delay(100);
}

void BAirLeft() {
  digitalWrite(left, HIGH);
  delay(250);
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  delay(50);
  digitalWrite(right, LOW);
  digitalWrite(Y, HIGH);
  delay(50);
  digitalWrite(Y, LOW);
  digitalWrite(left, HIGH);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(left, LOW);
  digitalWrite(A, LOW);
}

void BairRight() {
  digitalWrite(right, HIGH);
  delay(250);
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);
  delay(50);
  digitalWrite(left, LOW);
  digitalWrite(Y, HIGH);
  delay(50);
  digitalWrite(Y, LOW);
  digitalWrite(right, HIGH);
  digitalWrite(A, HIGH);
  delay(600);
  digitalWrite(right, LOW);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}

void smashAttack(int direct, int wait = 200) {
  digitalWrite(A, HIGH);
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(A, LOW);
  digitalWrite(direct, LOW);
  delay(350);
}

void tilt(int direct) {
  digitalWrite(direct, HIGH);
  delay(100);
  button40(A);
  digitalWrite(direct, LOW);
  delay(500);
}

void testingCombo() {
  reset();
  button40(right);
  grabDownThrow();
  delay(600);
  Uair(right);
  delay(250);
  button40(down);
  delay(300);
  Nair(right);
  Nair(left);
}

void NairLoop() {
  reset();
  button40(right);
  grabDownThrow();
  delay(600);
  Nair();
  tilt(up);
  Nair(left);
  tilt(up);
  Nair(right);
  tilt(up);
  Nair();
}


int nairCounter = 0;

void NairLoop1() {
  reset();
}

void NairLoop2() {
  button40(right);
}

void NairLoop3() {
  grabDownThrow();
}

void NairLoop4() {
  delay(600);
}


void NairLoop5() {
  Nair();
}

void NairLoop6() {
  tilt(up);
}

void NairLoop7() {
  Nair(left);
}

void NairLoop8() {
  tilt(up);
}

void NairLoop9() {
  Nair(right);
}

void NairLoop10() {
  tilt(up);
}


void NairLoop11() {
  Nair(left);
}

void NairLoop12() {
  tilt(up);
}

void NairLoop13() {
  Nair(right);
}

void NairLoop14() {
  tilt(up);
}


void NairLoop15() {
  Nair(left);
}

void NairLoop16() {
  tilt(up);
}

void NairLoop17() {
  delay(75);
  Nair(right);
}


void setup() {
  Serial.begin(9600);
  pinMode(start, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(Z, OUTPUT);
  pinMode(LR, OUTPUT);
  nairCounter = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
   char key = customKeypad.getKey();
   if (nairCounter == 0) {
   } else if (nairCounter == 1) {
    NairLoop1();
   } else if (nairCounter == 2) {
    NairLoop2();
   } else if (nairCounter == 3) {
    NairLoop3();
   } else if (nairCounter == 4) {
    NairLoop4();
   } else if (nairCounter == 5) {
    NairLoop5();
   } else if (nairCounter == 6) {
    NairLoop6();
   } else if (nairCounter == 7) {
    NairLoop7();
   } else if (nairCounter == 8) {
    NairLoop8();
   } else if (nairCounter == 9) {
    NairLoop9();    
   } else if (nairCounter == 10) {
    NairLoop10();
   } else if (nairCounter == 11) {
    NairLoop11();
   } else if (nairCounter == 12) {
    NairLoop12();
   } else if (nairCounter == 13) {
    NairLoop13();
   } else if (nairCounter == 14) {
    NairLoop14();
   } else if (nairCounter == 15) {
    NairLoop15();
   } else if (nairCounter == 16) {
    NairLoop16();
   } else if (nairCounter == 17) {
    NairLoop17();
   } else {
    nairCounter == 0;
   }
   if (nairCounter != 0) {
    nairCounter++;
   }
   if (key == '1') {
     button40(RTilt);
     
   } else if (key == '2') {
     button40(up);
    
   } else if (key == '3') {
     button40(LTilt);
    
   } else if (key == 'A') {
     button40(A, 20);
    
   } else if (key == '4') {
    button40(left);
    
   } else if (key == '5') {
     smashAttack(up, 10); 

   } else if (key == '6') {
     button40(right);
    
   } else if (key == 'B') {
     button40(B);
   
   } else if (key == '7') {
     tilt(up);
    
   } else if (key == '8') {
     button40(down);

   } else if (key == '9') {
     tilt(down);
    
   } else if (key == 'C') {
   
   } else if (key == '*') {
     nairCounter = 1;

   } else if (key == '0') {
     grabDownThrow();
     
   }else if (key == '#' && lastKey == '#') {
     reset();
   } else if (key == '#') {
     button40(start);
   }else if (key == 'D') {
   }
}
