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

void __interrupt() kesme(void){
	
		if(RBIF==1 & ((RB4==1)|(RB5==1)|(RB6==1)|(RB7==1))){//EĞER FLAGLAR 1 OLURSA BURAYA GÖRE HAREKER EDECEK
			RA0=1;;
			__delay_ms(2000);
			
		}
		RBIF=0;//RB İÇİN GÖSTERGE BAYRAĞI
		RA0=0;
}

void main(void) {

GIE=1;
RBIE=1;//YETKİLENDİRME BAYRAĞI RB İÇİN

TRISB=0xF0;
TRISA=0;//ÇIKIŞ AYARLIYOR
PORTA=0;

	while(1){
		RB1=0; __delay_ms(500);
		RB1=1; __delay_ms(500);

	}

}
