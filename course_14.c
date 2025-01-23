//step motor yarım adımkodları bipolar
/*
 * File:   sonpic.c
 * Author: MONSTER
 *
 * Created on 19 Eylül 2024 Per?embe, 10:22
 */

// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/Resonator on RA6/OSC2/CLKOUT pin, RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>

#define _XTAL_FREQ 4000000    // 4 MHz Kristal frekans?
int i, dizi[8]={1,3,2,6,4,12,8,9};


void main(void) {
    
    TRISA=1;
    TRISB=0;
    
    i=0;
    

    while (1) {
        PORTB=dizi[i];
        __delay_ms(2000);
		
        if(RA0==0){
            if(i==7){i=-1;}
            i++; 
        }
        else{
            if(i==0){i=8;}
            i--;           
        }       
    }
}
