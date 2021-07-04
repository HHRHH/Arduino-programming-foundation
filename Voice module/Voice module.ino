/*
rst is 13
data is 12
busy is 9
*/

volatile int sz;
int nan[]={2, 3, 19};

boolean mixly_digitalRead(uint8_t pin) {
  pinMode(pin, INPUT);
  boolean _return =  digitalRead(pin);
  pinMode(pin, OUTPUT);
  return _return;
}

void voiceWord(int Rst, int Data, int Busy, int No) {
  pinMode(Rst, OUTPUT);
  digitalWrite(Rst,LOW);
  delayMicroseconds(2);
  pinMode(Rst, OUTPUT);
  digitalWrite(Rst,HIGH);
  delayMicroseconds(100);
  pinMode(Rst, OUTPUT);
  digitalWrite(Rst,LOW);
  delayMicroseconds(100);
  for (int i = (1); i <= (No); i = i + (1)) {
    pinMode(Data, OUTPUT);
    digitalWrite(Data,HIGH);
    delayMicroseconds(100);
    pinMode(Data, OUTPUT);
    digitalWrite(Data,LOW);
    delayMicroseconds(100);
  }
  while (mixly_digitalRead(Busy)) {
  }
}

void setup(){
  sz = 1;
}

void loop(){
  voiceWord(13, 12, 9, nan[(int)(sz - 1)]);
  switch (sz) {
   case 1:
    delay(500);
    break;
   case 2:
    delay(1000);
    break;
   default:
    delay(1500);
    break;
  }
  sz++;
  if (sz == sizeof(nan)/sizeof(nan[0]) + 1) {
    sz = 1;

  }

}
