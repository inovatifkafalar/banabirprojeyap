#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int buttonPin1 = 2;
int buttonPin2 = 3;

int buttonValue1;
int buttonValue2;

int count = 0;
int rest = 20;

LiquidCrystal_I2C myLcd(0x27, 16, 2);

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  myLcd.init();
  myLcd.backlight();

}

void loop() {
  buttonValue1 = digitalRead(buttonPin1);
  buttonValue2 = digitalRead(buttonPin2);

  if (buttonValue1 == HIGH) {
    count = count + 1; // count++ , count+=1
    delay(500);
  }

  else if (buttonValue2 == HIGH) {
    count = count - 1; // count-- , count-=1
    delay(500);
  }

  myLcd.setCursor(0, 0);
  myLcd.print("YS:");
  myLcd.setCursor(5, 0);
  myLcd.print(count);

  myLcd.setCursor(0, 1);
  myLcd.print("KS:");
  myLcd.setCursor(5, 1);
  myLcd.print(rest - count);

  if (rest - count == 0) {
    count = 0;
    rest = 20;
  }

  delay(500);
  myLcd.clear();




}
