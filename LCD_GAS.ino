#include <LiquidCrystal.h>
#include <LCDKeypad.h>
const int analogInPin1 = A5;
int GasSensor1 = 0;
#define DELTA 10
LCDKeypad lcd;
unsigned char bckl=20;

void setup()
{
pinMode(DELTA, OUTPUT);
analogWrite(10, bckl);
lcd.begin(16, 2);
lcd.clear();
}
void loop()
{
int btn;
int x = analogRead (0);
while ((btn=lcd.button())==KEYPAD_NONE)
{
GasSensor1 = analogRead(analogInPin1);
lcd.setCursor(0, 0);
lcd.print("Natural Gas LPG:");
lcd.setCursor(0, 1);
lcd.print(GasSensor1);
lcd.setCursor(8, 1);
lcd.print("PPM");
if(GasSensor1>30)
{tone(12, 120);}
else{noTone(12);}
lcd.clear();
}
delay(10);
lcd.noBlink();
//wait for button release
while(lcd.button()!=KEYPAD_NONE){}
//adjust the backlight
if(btn==KEYPAD_RIGHT)
{if((0xFF-DELTA)>=bckl)
bckl +=DELTA;
else bckl=0xFF;}
else if(btn==KEYPAD_LEFT)
{if(DELTA<=bckl)
bckl -= DELTA;
else bckl = 0;}
analogWrite(10, bckl);
}
