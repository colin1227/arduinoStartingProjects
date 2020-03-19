int l1 = 6;
int s1 = 10;
int s2 = 11;
int val = 0;
void setup() {
}

void asc(int r) {
  for (int i = 0; i <= r; i++) {
    analogWrite(l1, val);
    analogWrite(s1, val);
    analogWrite(s2, val);
    delay(5);
    if (val <= 255) {
      val = val + 1;
    } else {
      val = 0;
    }
  }
}

void dec(int r) {
  for (int i = 0; i >= r; i--) {
    analogWrite(l1, val);
    analogWrite(s1, val);
    analogWrite(s2, val);
    delay(5);
    if (val > 0) {
      val = val - 1;
    } else {
      val = 0;
    }
  }
}
void loop() {
  
}
