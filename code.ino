// Pin setup
const int ldrPin = A0;
const int irPin = 2;
const int trigPin = 3;
const int echoPin = 4;
const int ledPin = 13;

// Variables
int ldrValue = 0;
bool isNight = false;
int distance = 0;
bool motionDetected = false;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Read LDR
  ldrValue = analogRead(ldrPin);
  isNight = ldrValue < 40;  // Adjust this based on your test
  
  // Read IR sensor
  int irValue = digitalRead(irPin);

  // Read ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // in cm

  // Determine if motion is detected (IR or ultrasonic)
  motionDetected = (irValue == LOW || distance < 100); // adjust distance as needed

  // Decision to turn LED ON or OFF
  if (isNight && motionDetected) {
    digitalWrite(ledPin, HIGH); // Turn ON LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn OFF LED
  }

  // Debugging output
  Serial.print("LDR: "); Serial.print(ldrValue);
  Serial.print(" | Night: "); Serial.print(isNight ? "Yes" : "No");
  Serial.print(" | IR: "); Serial.print(irValue == LOW ? "Detected" : "None");
  Serial.print(" | Distance: "); Serial.print(distance); Serial.print(" cm");
  Serial.print(" | LED: "); Serial.println(digitalRead(ledPin) ? "ON" : "OFF");

  delay(500); // slow down loop
}