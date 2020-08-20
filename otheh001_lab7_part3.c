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
    /* Insert your solution below */
    ADC_init();
    unsigned char threshold=0x20;
    unsigned char ledsb=0x00;
    while (1) {
	unsigned char leds=ADC;
	if (leds>=threshold) {
	    ledsb=0x01;
	}
	else {
	    ledsb=0x00;
	}
	PORTB=ledsb;
    }
    return 1;
}
