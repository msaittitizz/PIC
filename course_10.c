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
void __interrupt() kesme(void) {
    

    if(CCP1IF){
        RC2=RC2 ^1;
      
    }
 
    CCP1IF=0;

}

void main(void) {
    GIE = 1;           // Global kesmeleri etkinle?tir
    PEIE = 1;          // EEPROM yazma kesmesini etkinle?tir
    TMR1IE=1;
    TMR1CS=1;//SAYICI OLARAK KULLANDIK-0 OLSA ZAMANLAYICI
 
	T1OSCEN=1; //İÇ OSİLATÖRÜ AKTİF EDİYOR UYKU MODUNDA ÇALIŞSIN DİYE
    TMR1ON=1;//TMR1 ÇALIŞMASI YETKİLENDİRME 

    TMR1=1;
    TRISC = 1;      // RC0 giri? olarak ayarla 0B0000 0001
	
    CCP1M0=1;
    CCP1M1=1;
    CCP1M2=0;
    CCP1M3=1;
	
    CCP1IE=1;// YETKİ
	
	CCPR1=5; //5 OLURSA LED YANACAK YA DA SÖNECEK*******************
	
	RC2=0;
    
    while(1){}
}
