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
    unsigned char MAX=64;
    unsigned char inc=5; //Since MIN=24
    unsigned char ledsb=0x00;
    while (1) {
	unsigned char leds=ADC;
	if (leds>=(MAX-1)) {
	    ledsb=0xFF;
	}
	else if (leds>=(MAX-inc)) {
	   ledsb=0x7F;
	}
	else if (leds>=(MAX-(2*inc))) {
	    ledsb=0x3F;
	}
	else if (leds>=(MAX-(3*inc))) {
	    ledsb=0x1F;
	}
	else if (leds>=(MAX-(4*inc))) {
	    ledsb=0x0F;
        }
	else if (leds>=(MAX-(5*inc))) {
	    ledsb=0x07;
        }
	else if (leds>=(MAX-(6*inc))) {
	    ledsb=0x03;
	}
	else if (leds>=(MAX-(7*inc))) {
	    ledsb=0x01;
	}
	else {
	    leds=0x00;
	}
	PORTB=ledsb;
    }
    return 1;
}
