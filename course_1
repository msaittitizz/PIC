/*
 * File:   lastdateolan.c
 * Author: MONSTER
 *
 * Created on 14 Eylül 2024 Cumartesi, 14:10
 */

// PIC16F877 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low Voltage In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF         // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000

int i,j,k;

int satir[2][5]={0x15,0x25,0x55,0x65,0x01,
				 0x15,0x25,0x55,0x65,0x01}




void main(void) {
	 TRISC=0;
	 TRISB=0;
	
	while(1){
		for(k=0;k<2;k++){
			for(j=0;j<100;j++){
				PORTC=1;
					for(i=0;i<5;i++){
						PORTB=satir8[k][i];
						__delay_ms(5);
						PORTC=PORTC<<1;
					}
			}
		}	
	}
}
