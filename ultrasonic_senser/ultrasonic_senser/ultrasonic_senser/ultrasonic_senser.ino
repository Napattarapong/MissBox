#define BUZZER_PIN D3

#define echoPin D2
#define trigPin D1

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Serial.println(Ultrasonic());
  int cm = Ultrasonic();
  if (cm < 20 && cm != 0) {     
    digitalWrite(BUZZER_PIN, LOW);
    delay(1000);
  }
  else {                             
    digitalWrite(BUZZER_PIN, HIGH);   
    delay(1000);
  }
}

int Ultrasonic() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  return distance;
}