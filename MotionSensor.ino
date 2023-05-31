#define GREEN 3
#define RED 4
#define BUTTON 7
#define TRIG 9
#define ECHO 10

int pushed;
long duration;
int initialDistance, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);

  delay(3000);

  digitalWrite(RED, LOW);

  initialDistance = getDistance();
}

void loop() {
  // put your main code here, to run repeatedly:

  distance = getDistance() + 15;

  if (distance < initialDistance) {
    detected();
  }
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  return distance;
}

void detected() {
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, HIGH);
  pushed = digitalRead(BUTTON);

  while (pushed == LOW) {
    pushed = digitalRead(BUTTON);
  }

  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);

  delay(3000);

  digitalWrite(RED, LOW);

  initialDistance = getDistance();
}
