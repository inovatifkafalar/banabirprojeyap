int enablePin = 9;
int in1Pin = 10;
int in2Pin = 11;
int potxPin = A0;
int potyPin = A1;
int potxValue;
int potyValue;

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  potxValue = analogRead(potxPin);
  potyValue = analogRead(potyPin);
  Serial.println(potxValue);
  Serial.println(potyValue);

  if (potyValue > 600) {
    analogWrite(enablePin, 150);
    digitalWrite(in2Pin, 1);
  }
  
  else if (potyValue < 400) {
    analogWrite(enablePin, 150);
    digitalWrite(in1Pin, 1);
  }
  
  else{
    digitalWrite(in1Pin, 0);
    digitalWrite(in2Pin, 0);
  }

}
