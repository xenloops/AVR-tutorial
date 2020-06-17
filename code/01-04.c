/*
* AVR cybernetic display firmware
* written by: Nathan Larson (@xenloops)
* November 2019
*
* ATmega88PU
* 
* s01e04 -- Interrupting flasher
*/

//#define F_CPU 1000000UL
#include <avr/io.h>
//#include <util/delay.h>
#include <avr/interrupt.h>
//#include <stdlib.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define WAIT(ms); _delay_ms(ms)

int main(void)
{
   // Setup the timer
   cli();                  //Disable global interrupts
   SETBIT(TCCR1B, CS10);
   SETBIT(TCCR1B, CS11);   //Divide by 64
   OCR1A = 15624;          //15624 = 1 second interrupt
   SETBIT(TCCR1B, WGM12);  //Put Timer/Counter1 in CTC mode
   SETBIT(TIMSK1, OCIE1A); //enable timer compare interrupt
   sei();                  //Enable global interrupts

   // Setup I/O for the LED
   SETBIT(DDRB, PINB1);		// Set Port B Pin 1 to output
   CLEARBIT(PORTB, PINB1);		// Set Port B Pin 1 low to turn off LED
   
   //Loop forever
   while(1) {
      // Do nothing; the interrupt handles functionality
   } 
}

ISR(TIMER1_COMPA_vect)		 //Interrupt Service Routine
{                          //toggles LED
   if (CHECKBIT(PINB, PINB1)) // if LED on, turn off
      CLEARBIT(PORTB, PINB1);
   else                       // if LED off, turn on
      SETBIT(PORTB, PINB1);
}



