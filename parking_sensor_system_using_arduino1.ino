int sigPin = 9;

int red = 11;
int green = 10;
int blue = 6;

int buzzer = 8;

long duration;
int distance;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send pulse
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sigPin, LOW);

  // Read echo
  pinMode(sigPin, INPUT);
  duration = pulseIn(sigPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Logic
  if (distance < 10) {
    // RED + buzzer
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, HIGH);
  }
  else if (distance < 20) {
    // YELLOW (Red + Green)
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, LOW);
  }
  else {
    // GREEN safe
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(300);
}
