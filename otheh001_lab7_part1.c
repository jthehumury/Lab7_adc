/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA|=(1<<ADEN)|(1<<ADSC)|(1<<ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA=0x00;PORTA=0xFF;
    DDRB=0xFF;PORTB=0x00;
    DDRD=0xFF;PORTD=0x00;
    /* Insert your solution below */
    ADC_init();
    while (1) {
	unsigned short leds=ADC;
	unsigned char ledsb=(char)leds;
	unsigned char ledsd=(char)(leds>>8);
	PORTB=ledsb;
	PORTD=ledsd;
    }
    return 1;
}
