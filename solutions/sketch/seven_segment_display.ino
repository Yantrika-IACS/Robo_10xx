// 7-segment display
// Common cathode
// Segments: a, b, c, d, e, f, g

int segments[] = {2, 3, 4, 5, 6, 7, 8};

// Each row represents a digit 0-9
// Order: a b c d e f g
byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
  }
}

void displayDigit(int number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], digits[number][i]);
  }
}

void loop() {
  for (int number = 0; number <= 9; number++) {
    displayDigit(number);
    delay(1000);
  }
}
