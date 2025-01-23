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



#define _XTAL_FREQ 4000000    // 4 MHz Kristal frekansı
int sayac, zaman;

void __interrupt() kesme(void) {
    
    if (TMR1IF) { 
        sayac++;    
    }
    if(CCP1IF){
        zaman=(65536*sayac+CCPR1)/1000000;
        if(zaman>=255){
            zaman=0;
            sayac=0;
        }   
        PORTB=zaman;
        sayac=0;
        zaman=0;
    }
    TMR1IF=0;
    CCP1IF=0;
    TMR1=0;
}

void main(void) {
    sayac = 0;         // Sayacı sıfırla
    GIE = 1;           // Global kesmeleri etkinleştir
    PEIE = 1;          // EEPROM yazma kesmesini etkinleştir
    TMR1IE=1;
    TMR1CS=0;
    T1CKPS1=0;
    T1CKPS0=0;
    TMR1ON=1;
    PORTB = 0;         // PORTD'yi sıfırla (başlangıç durumu)
    TMR1=0;
    TRISB = 0;      // PORTD çıkış olarak ayarla
    TRISC = 0x04;      // RC2 giriş olarak ayarla
    CCP1M0=1;
    CCP1M1=0;
    CCP1M2=1;
    CCP1M3=0;
    CCP1IE=1;
    
    while(1){}
}
