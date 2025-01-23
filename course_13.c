//DC MOTOR SÜRÜCÜSÜ H KÖPRÜSÜ VE PWM AYARLAMA
/*
 * File:   sonpic.c
 * Author: MONSTER
 *
 * Created on 19 Eylül 2024 Perşembe, 10:22
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

#define _XTAL_FREQ 4000000    // 4 MHz Kristal frekansı

void __interrupt() KESME(void) {
    if (RBIF) {
        if (RB6 == 0) {
            PORTD = 5;
        } else {
            PORTD = 10;
        }

        if (RB5) {
            if (CCPR1L > 245) {
                CCPR1L = 1;
            }
            CCPR1L += 20;
        }

        if (RB4) {
            if (CCPR1L == 0) {
                CCPR1L = 245;
            }
            CCPR1L -= 20;
        }

        RBIF = 0;
    }
}

void main(void) {
    OPTION_REGbits.nRBPU = 0; // PORTB pull-up aktif
    INTCONbits.GIE = 1;       // Genel kesme aktif
    INTCONbits.RBIE = 1;      // RB kesmesi aktif
    INTCONbits.RBIF = 0;      // RB kesme bayrağı sıfırlandı
    
    T2CKPS1 = 0;
    T2CKPS0 = 1;
    TMR2ON = 1;
    PR2 = 249;

    CCP1M2 = 1;
    CCP1M3 = 1;
    CCPR1L = 125; // Duty cycle %50

    TRISB = 0xFF;  // RB giriş
    TRISD = 0x00;  // RD çıkış
    PORTD = 0x00;  // RD portu kapalı
    TRISC = 0x00;  // RC çıkış (PWM)

    while (1) {
        // Ana döngü burada çalışacak
    }
}
