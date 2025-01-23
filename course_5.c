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

void __interrupt() kesme(void){//KESME FONKSİYONUNU HEP TANIMLIYORUZ
	
		if(TOIF){//EĞER FLAGLAR 1 OLURSA BURAYA GÖRE HAREKER EDECEK
			sayac++
			if (sayac==0){
				sayac=0;
				RB0=RB0 ^ 1; //0000 0001
			}
			TOIE=0;//TMR0 İÇİN GÖSTERGE BAYRAĞI
			TMR0=61;
		}

}

void main(void) {

GIE=1; //TÜM KESMELERİ YETKİLENDİRME BAYRAĞI
TOIF=1;//YETKİLENDİRME BAYRAĞI TMR0 İÇİN
OPTION_REG=0X07;//0B 0000 0111

TRISB=0x00;
TMR0=61;//0,5SN ELDE ETMEK İÇİN
sayac=0;
PORTB=0;// İLK DURUMDA LOW YAPTIK

	while(1){

	}

}
