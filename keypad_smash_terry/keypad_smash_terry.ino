#include <Keypad.h>
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
const int RTilt = 43;
const int LTilt = 42;
const int DTilt = 11;
const int UTilt = 12;
char lastKey = "";
const int timeToWait = 500;
boolean runMe = false;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

byte colPins[ROWS] = {2, 3, 4, 5};
byte rowPins[COLS] = {6, 7, 8, 9};

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
  digitalWrite(LR, HIGH);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(LR, LOW);
  digitalWrite(A, LOW);
  delay(100);
}


void fullHop() {
  digitalWrite(Y, HIGH);
  delay(100);
  digitalWrite(Y, LOW);
}

void shortHop() {
  digitalWrite(Y, HIGH);
  delay(40);
  digitalWrite(Y, LOW);
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

void Bair(int backward = left, int forward = right, boolean fastfall = true) {
  digitalWrite(Y, HIGH);
  digitalWrite(forward, HIGH);
  delay(40);
  digitalWrite(Y, LOW);
  delay(85);
  digitalWrite(forward, LOW);
  digitalWrite(backward, HIGH);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(backward, LOW);
  delay(300);

  delay(100);
  digitalWrite(Y, LOW);
  digitalWrite(A, LOW);
  delay(100);
  if (fastfall) {
    digitalWrite(down, LOW);
  }
  delay(100);
}

void Fair(int backward = left, int forward = right, boolean fastfall = true) {
  button40(Y);
  digitalWrite(forward, HIGH);
  delay(125);
  digitalWrite(A, HIGH);
  delay(100);
  delay(300);
  if (fastfall) {
    digitalWrite(down, HIGH);
  }
  delay(100);
  digitalWrite(Y, LOW);
  digitalWrite(A, LOW);
  digitalWrite(forward, LOW);
  delay(100);
  if (fastfall) {
    digitalWrite(down, LOW);
  }
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
  if (direct == up || direct == down) {
    digitalWrite(direct, HIGH);
    delay(150);
    button40(A);
    digitalWrite(direct, LOW);
    delay(500);
  } else {
    button40(direct);
  }
}

void dashAttack(int direct) {
  digitalWrite(direct, HIGH);
  delay(150);
  button40(A);
  digitalWrite(direct, LOW);
}

void PG() {
  button40(down);
  button40(left);
  button40(down);
  button40(right);
  digitalWrite(B, HIGH);
  delay(100);
  digitalWrite(B, LOW);
}

void BW() {
  button40(down, 25);
  button40(right, 25);
  button40(down, 25);
  button40(right, 25);
  digitalWrite(B, HIGH);
  delay(100);
  digitalWrite(B, LOW);
}

void powerDunk() {
  digitalWrite(down, HIGH);
  digitalWrite(B, HIGH);
  delay(250);
  digitalWrite(down, LOW);
  digitalWrite(B, LOW);
  delay(700);
}

void crackShoot(int backward) {
  digitalWrite(backward, HIGH);
  digitalWrite(B, HIGH);
  delay(250);
  digitalWrite(backward, LOW);
  digitalWrite(B, LOW);
}

void burningKnuckle(int forward) {
  digitalWrite(forward, HIGH);
  digitalWrite(B, HIGH);
  delay(500);
  digitalWrite(forward, LOW);
  digitalWrite(B, LOW);
}

void testingCombo() {
  for (int x = 0; x < 10; x++) {
    button40(right);
    delay(100);
    tilt(DTilt);
    powerDunk();
    if (x != 9) {
      reset();

    }
  }
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
  reset();
//  testingCombo();
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = customKeypad.getKey();
  if (key != false) {
    Serial.println(key);
  }
  if (key == '1') {
    PG();

  } else if (key == '2') {
    button40(up, 200);

  } else if (key == '3') {
    BW();
  } else if (key == 'A') {
    button40(A);

  } else if (key == '4') {
    button40(left, 200);

  } else if (key == '5') {
    testingCombo();

  } else if (key == '6') {
    button40(right, 200);

  } else if (key == 'B') {
    button40(B);

  } else if (key == '7') {
    tilt(up);

  } else if (key == '8') {
    button40(down, 200);

  } else if (key == '9') {
    tilt(down);

  } else if (key == 'C') {
    smashAttack(down, 500);

  } else if (key == '*') {
    testingCombo();

  } else if (key == '0') {
    grabDownThrow();

  } else if (key == '#') {
    if (runMe) {
      reset();
      button40(B);
      runMe = false;
    } else {
      button40(start);
      runMe = true;
    }

  } else if (key == 'D') {
    reset();
  }

}
