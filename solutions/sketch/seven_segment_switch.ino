// 7-segment display
// Common cathode
// Segments: a, b, c, d, e, f, g

int segments[] = {2, 3, 4, 5, 6, 7, 8};
int number = 0;

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
  pinMode(9, INPUT);
  displayDigit(number) ;
}

void displayDigit(int number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], digits[number][i]);
    delay ( 100 );
  }
}

void loop() {
  int buttonState = digitalRead(9);

  if (buttonState == HIGH) {
    number = number + 1;

    if (number > 9) {
      number = 0;
    }

    displayDigit(number);

    delay(200);
  }
}
