/*
5 is the button
4 is the light
SCL and SDA are four digit nixie tube 1650 interface
*/



#include <Wire.h>
#include <TM1650.h>

volatile int a;
volatile int b;
TM1650 tm_4display;

void setup(){
  a = 0;
  b = 0;
  pinMode(5, INPUT);
  Wire.begin();
  tm_4display.init();
}

void loop(){
  if (digitalRead(5) == 0) {
    while (digitalRead(5) == 0) {
    }
    a++;
    tm_4display.displayString(String(a));
    if ((long) (a) % (long) (2) == 0) {
      for (int b = 0; b <= 255; b = b + (5)) {
        analogWrite(3,b);
        delay(30);
      }

    } else {
      for (int b = 255; b >= 0; b = b + (-5)) {
        analogWrite(3,b);
        delay(30);
      }

    }

  }

}
