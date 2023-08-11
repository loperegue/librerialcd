#ifndef LCD20X4
#define LCD20X4 

#include "MKL25Z4.h"
#include "delay.h"

void lcd.init();
void lcd.clear();
void lcd.setCursor(int, int);
void lcd.print(    );
void lcd.shiftLeft();
void lcd.shiftRight();
void lcd.bLightOn();
void lcd.bLightOff();

#endif