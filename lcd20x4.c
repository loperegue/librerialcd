 #include "delay.h"
 #include "MKL25Z4.h"

void lcd.init(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
    PORTA -> PCR[0] = PORT_PCR_MUX(1);
    PORTA -> PCR[1] = PORT_PCR_MUX(1);
    PORTA -> PCR[2] = PORT_PCR_MUX(1);
    PORTA -> PCR[3] = PORT_PCR_MUX(1);
    PORTA -> PCR[4] = PORT_PCR_MUX(1);
    PORTA -> PCR[5] = PORT_PCR_MUX(1);
    PORTA -> PCR[6] = PORT_PCR_MUX(1);
    PORTA -> PCR[7] = PORT_PCR_MUX(1);
    PORTA -> PCR[8] = PORT_PCR_MUX(1);
    PORTA -> PCR[9] = PORT_PCR_MUX(1);
    PORTA -> PCR[10] = PORT_PCR_MUX(1);
    PORTA -> PCR[11] = PORT_PCR_MUX(1);
    lcd.clear();
}

void lcd.enable(){
    PTA -> PDOR = (1<<9);
    delay_ms(1);
    PTA -> PCOR = (1<<9);
}

void lcd.clear(){
    PTA -> PDOR = 0x00000001;
    lcd.enable();
    delay_ms(3);
    PTA -> PDOR = 0x00000000;
    lcd.enable();
}

void lcd.setCursor(int col, int fila){
    PTA -> PDOR = 0x0000000b;
    lcd.enable();
    for(int i=1, i < fila, i++){
        PTA -> PDOR = 0x0000000c;
        lcd.enable();
    }
    for(int i=1, i < col, i++){
        PTA -> PDOR = 0x0000000f;
        lcd.enable();
    }
}

void lcd.print(char word[20]){
    int p = 0, n;
    int data[8];
    PTA -> PDOR = (1<<11);
    while((int)(word[p]) > 0||p > 19){
        n = (int)(word[p]);
        for(i=0;n>0;i++)    
        {    
        data[i] = n % 2;    
        n = n / 2;    
        }
        p++;
        for(int i=0, i<7, i++){
            if(data[i]){
                PTA -> PDOR = (1<<data[i]);
            else
                PTA -> PCOR = (1<<data[i]);
            }
        }
        lcd.enable();
    }
    PTA -> PCOR = (1<<11);
}

void lcd.shiftLeft(){
    PTA -> PDOR = 0x00000018;
    lcd.enable();
}

void lcd.shiftRight(){
    PTA -> PDOR = 0x0000001c;
    lcd.enable();
}

void lcd.bLightOn(){
    PTA -> PDOR = 0x000000fe;
    lcd.enable();
    PTA -> PDOR = 0x00000006;
    lcd.enable();
}

void lcd.bLightOff(){
    PTA -> PDOR = 0x000000fe;
    lcd.enable();
    PTA -> PDOR = 0x00000007;
    lcd.enable();
}