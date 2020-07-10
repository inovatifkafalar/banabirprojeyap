#include <Servo.h>

Servo myServo;
int servoPin = 9;
int trig = 5;
int echo = 6;
int distance;
int duration;


void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(0);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print("Ultrasonic Sensor: ");
  Serial.println(distance);
  if (distance < 15) {
    myServo.write(0);
  }
  else {
    myServo.write(180);
    delay(200);
    myServo.write(0);
    delay(200);

  }
}
