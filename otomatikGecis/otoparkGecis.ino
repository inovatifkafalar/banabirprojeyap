#include <Servo.h>
#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid (SS_PIN, RST_PIN);
Servo myServo;

int cardNum;
int potPin = A0;
int potValue;
int servoPin = 3;

void setup() {
  Serial.begin(9600);
  SPI.begin();  //SPI!ın haberleşmesini başlatır.
  rfid.init();
  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      cardNum = rfid.serNum[0];
      Serial.print("Card number: ");
      Serial.println(cardNum);
      if (cardNum == 80) {
        potValue = analogRead(potPin);
        potValue = map(potValue, 0, 1023, 0, 180);
        myServo.write(potValue);
      }
      else {
        myServo.write(0);
      }
      delay(500);
    }
  }
}
