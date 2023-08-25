#ifndef LCD20X4_H
#define LCD20X4_H

#include "MKL25Z4.h"
#include "delay.h"

void lcd.enable();
void lcd.init();
void lcd.clear();
void lcd.setCursor(int, int);
void lcd.print(char[20]);
void lcd.shiftLeft();
void lcd.shiftRight();
void lcd.bLightOn();
void lcd.bLightOff();

#endif