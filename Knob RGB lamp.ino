//SCL SDA It's a four digit nixie tube
//A5 It's a potentiometer
//D4 It's a button
//D9 D10 D11 It's RGB

#include <Wire.h>
#include <TM1650.h>

TM1650 tm_4display;
volatile int a;

#define R 9
#define G 10
#define B 11

void setup(){
  Wire.begin();
  tm_4display.init();
  a = 1;
  tm_4display.clear();
  pinMode(4, INPUT);
}

void loop(){
  while (digitalRead(4) == 0) {
    while (digitalRead(4) == 0) {
    }
    a++;
    if (a > 3) {
      a = 1;

    }
  }

  switch (a) {
   case 1:
    tm_4display.displayString(String((map(analogRead(A5), 0, 1023, 0, 255))));
    analogWrite(R,(map(analogRead(A5), 0, 1023, 0, 255)));
    break;
   case 2:
    tm_4display.displayString(String((map(analogRead(A5), 0, 1023, 0, 255))));
    analogWrite(G,(map(analogRead(A5), 0, 1023, 0, 255)));
    break;
   case 3:
    tm_4display.displayString(String((map(analogRead(A5), 0, 1023, 0, 255))));
    analogWrite(B,(map(analogRead(A5), 0, 1023, 0, 255)));
    break;
  }

}
