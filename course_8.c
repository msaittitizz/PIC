/*
 * File:   lastdateolan.c
 * Author: MONSTER
 *
 * Created on 14 Eylül 2024 Cumartesi, 14:10
 */

// PIC16F877 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT     // Oscillator Selection bits (RC oscillator)
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
int sayac;
void __interrupt() kesme(void){
	
		if(TMR2IF){//EĞER FLAGLAR 1 OLURSA BURAYA GÖRE HAREKER EDECEK
			sayac++;
			if(sayac==100){//SAYAC ARTTIKSA DAHA YAVAŞLAR
				sayac=0;
				RB0=RB0^1;//xor yapıyor ve 1-0 durumunda 1 oluyor aç akapa yapıyor
			}
			
		}
		TMR2IF=0;//TMR1 İÇİN GÖSTERGE BAYRAĞI
		TMR2=0;
}

void main(void) {
sayac=0;
GIE=1;
PEIE=1;// ÇEVRESEL YETKİ BİTLERİ
TMR2IE=1;//YETKİLENDİRME BAYRAĞI TMR2 İÇİN

T2CKPS1=1;//2Sİ DE BÖLME ORANINI AYARLIYOR 0 0 = 1, 1 1 =16
T1CKPS0=1;

TOUTPS3=1;//T2CON SAKLAYICISI/POSTSCALE ORANINI AYARLIYOR 1 1 1 1 = 1/16, 0 0 0 0 =1/1
TOUTPS2=1;
TOUTPS1=1;
TOUTPS0=1;

TMR2=0;//İLK DEĞER
TRISB=0;//ÇIKIŞ AYARLIYOR
PORTB=0;
PR2=255;

TMR2ON=1;

	while(1){
	

	}

}
