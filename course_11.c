/*
 * File:   eeprom_example.c
 * Author: MONSTER
 *
 * Created on 14 Eylül 2024 Cumartesi, 14:10
 */

// PIC16F877 Configuration Bit Settings
#include <xc.h>
// CONFIG
#pragma config FOSC = XT     // Oscillator Selection bits (XT Oscillator)
#pragma config WDTE = OFF    // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF   // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF      // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON   // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON     // Low Voltage In-Circuit Serial Programming Disable bit (RB3/PGM pin has PGM function; low-voltage programming disabled)
#pragma config CPD = OFF     // Data EEPROM Memory Code Protection (Code protection off)
#pragma config WRT = ON      // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



#define _XTAL_FREQ 4000000    // 4 MHz Kristal frekans?


void main(void) {
	TRISC=0;
	PR2=249;
   
	T2CKPS1=0;//BÖLME ORANI 4
	T2CKPS0=1;

    TMR2ON=1;//TMR1 ÇALIŞMASI YETKİLENDİRME 


    CCP1M2=1;//pwm mode geçildi
    CCP1M3=1;
	
    CCPR1L=125;
	

    while(1){}
}
