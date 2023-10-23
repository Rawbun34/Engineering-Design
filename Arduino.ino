// C++ code
//
// defines pins numbers
int trigPin1 = 13;
int echoPin1 = 12;
int trigPin2 = 11;
int echoPin2 = 10;
int trigPin3 = 9;
int echoPin3 = 8;
int pwmPin1 = 6;
int pwmPin2 = 5;
int pwmPin3 = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT); 
  pinMode(pwmPin1, OUTPUT); // Sets the pwmPin as an Output
  pinMode(pwmPin2, OUTPUT);
  pinMode(pwmPin3, OUTPUT);
}

void loop() {
  // Trigger Sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Measure the duration for Sensor 1
  long duration1 = pulseIn(echoPin1, HIGH);


  // Trigger Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  // Measure the duration for Sensor 2
  long duration2 = pulseIn(echoPin2, HIGH);
  
  // Trigger Sensor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  // Measure the duration for Sensor 1
  long duration3 = pulseIn(echoPin3, HIGH);

  // Calculate distances from durations
  float distance1 = duration1 * 0.034 / 2;  // Speed of sound is approximately 0.034 cm/µs
  float distance2 = duration2 * 0.034 / 2;
  float distance3 = duration3 * 0.034 / 2;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm | Distance 2: ");
  Serial.print(distance2);
  Serial.print(" cm | Distance 3: ");
  Serial.print(distance3);
  Serial.println(" cm");
  
// Trigger vibrator 1
  if (distance1 <= 30) {
    Serial.println("vibrate");
    digitalWrite(pwmPin1, HIGH);
  }
  else {
    Serial.println("stop");
    digitalWrite(pwmPin1, LOW);
  };
  
  // Trigger vibrator 2
  if (distance2 <= 30) {
    Serial.println("vibrate");
    digitalWrite(pwmPin2, HIGH);
  }
  else {
    Serial.println("stop");
    digitalWrite(pwmPin2, LOW);

  };
  
  // Trigger vibrator 3
  if (distance3 <= 30) {
    Serial.println("vibrate");
    digitalWrite(pwmPin3, HIGH);
  }
  else {
    Serial.println("stop");
    digitalWrite(pwmPin3, LOW);
  };
}