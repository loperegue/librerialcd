#include "lcd20x4" 
#include <delay.h>
#define d0 PTB->PCR[0]
#define d1 PTB->PCR[1]
#define d2 PTB->PCR[2]
#define d3 PTB->PCR[3]
#define d4 PTB->PCR[4]
#define d5 PTB->PCR[5]
#define d6 PTB->PCR[6]
#define d7 PTB->PCR[7]
#define rs PTB->PCR[8]
#define rw PTB->PCR[9]
#define e PTB->PCR[10]

void lcd.init(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
    PORTA -> PCR[0] = PORT_PCR_MUX(1);
    PORTA -> PCR[1] = PORT_PCR_MUX(2);
    PORTA -> PCR[2] = PORT_PCR_MUX(3);
    PORTA -> PCR[3] = PORT_PCR_MUX(4);
    PORTA -> PCR[4] = PORT_PCR_MUX(5);
    PORTA -> PCR[5] = PORT_PCR_MUX(6);
    PORTA -> PCR[6] = PORT_PCR_MUX(7);
    PORTA -> PCR[7] = PORT_PCR_MUX(8);
    PORTA -> PCR[8] = PORT_PCR_MUX(9);
    PORTA -> PCR[9] = PORT_PCR_MUX(10);
    PORTA -> PCR[10] = PORT_PCR_MUX(11);
    rs = 1;
    rw = 1;
    e = 0;
    lcd.clear();
}

void lcd.clear(){
    PTA -> PDOR = 0x00000001;
    delay_ms(3);
    PTA -> PDOR = 0x00000000;
}

void lcd.setCursor(int fila, int col){
    int A[4] = {00, 14, 40, 54};
    char 
    PTA -> PDOR = 0x00000000;
}