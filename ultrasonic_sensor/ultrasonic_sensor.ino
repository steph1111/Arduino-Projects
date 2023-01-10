const int beep_distance = 20;
int echo_pin = 2;
int trig_pin = 3;
int red_pin = 8;  // also buzzer
int green_pin = 9;
float distance;
float duration;


void setup() {
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);

  pinMode(red_pin, OUTPUT);
  digitalWrite(red_pin, LOW);

  pinMode(green_pin, OUTPUT);
  digitalWrite(green_pin, HIGH);

  Serial.begin(9600);
}

void loop() {
  time_measurement();
  distance = (float)duration * (0.0343) / 2;
  Serial.println(distance);
  alarm_condition();
}

void time_measurement() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
}

void alarm_condition() {
  if (distance <= beep_distance) {
    digitalWrite(red_pin, HIGH);
    digitalWrite(green_pin, LOW);
  } else {
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, HIGH);    
  }
}
