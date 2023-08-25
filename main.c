#include <mbed.h>
#include "MKL25Z4.h"
#include "lcd20x4.h"
#include "Delay.h"

int main() {
    lcd.init();
    lcd.bLightOn();
    int cont=0;
    lcd.setCursor(2, 1);
    lcd.print("contador:");
    lcd.setCursor(5, 2);
    while(1) {
        while(cont < 100){
            lcd.print(cont);
            delay_ms(1000);
        }
        lcd.shiftLeft();
        delay_ms(300);
    }
}