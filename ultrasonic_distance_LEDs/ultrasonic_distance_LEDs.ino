// https://www.youtube.com/watch?v=ysuVdbJhHV4s


int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int trig = 6;
int echo = 7;
float distance, duration;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  digitalWrite(greenLED, HIGH);
  Serial.begin (9600);
}

void loop() {
  time_measurement();
  distance = duration * 0.0343 / 2;
  display_distance();
}

void time_measurement() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
}

void display_distance() {
  Serial.print("Distance in cm: ");
  Serial.print(distance);
  Serial.println();

  if (distance >= 20) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  } else if (distance >= 10) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }
}
