#define INT1 16
#define INT2 17
#define INT3 18
#define INT4 19

void setup() {
  Serial.begin (9600);
  pinMode(INT1, OUTPUT);
  pinMode(INT2, OUTPUT);
  pinMode(INT3, OUTPUT);
  pinMode(INT4, OUTPUT);
}

void loop() {
  forward();
  delay(3000);
  stop();
  delay(5000);
  backward();
  delay(3000);
  stop();
  delay(5000);
}

void forward() {
  analogWrite(INT1, 100);
  analogWrite(INT2, 0);
  analogWrite(INT3, 0);
  analogWrite(INT4, 100);
}

void backward() {
  analogWrite(INT1, 0);
  analogWrite(INT2, 100);
  analogWrite(INT3, 100);
  analogWrite(INT4, 0);
}

void stop() {
  analogWrite(INT1, 0);
  analogWrite(INT2, 0);
  analogWrite(INT3, 0);
  analogWrite(INT4, 0);
}
