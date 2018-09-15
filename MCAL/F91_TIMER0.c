

#include <avr/io.h>
#include <avr/interrupt.h>
#include "F91_TIMER0.h"
#include "../Services_layers/Services_layers.h"
#include "../HAL/F91_Leds.h"

volatile unsigned long counter = 0;
volatile unsigned long counter1 = 0;

void F91_void_TIMER0_init()
{
	TCCR0 = (1 << CS01) | (1 << CS00);
	TIMSK = (1 << TOIE0);
	sei();
}


//ISR(TIMER0_OVF_vect)
//{
//	counter++;
//	counter1++;
//
//
//
//
//}
