/*
* AVR cybernetic display firmware
* written by: Nathan Larson (@xenloops)
* November 2019
*
* ATmega88PU
* 
* s01e02a -- A more enlightened LED
* Push a button, toggle the LED.
*/

#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define WAIT(ms); _delay_ms(ms)

int main(void)
{
   // Setup I/O for the LED
   SETBIT(DDRB, PINB1);		// Set Port B Pin 1 to output
   CLEARBIT(PORTB, PINB1);		// Set Port B Pin 1 low to turn off LED
   
   // Setup I/O for the button
   CLEARBIT(DDRB, PINB0);  // Set Port B Pin 0 to input
   SETBIT(PORTB, PINB0);   // activate internal pull-up resistor
   
   //Loop forever
   while(1) {
      if (!CHECKBIT(PINB, PINB0)) // If button pressed...
         if (CHECKBIT(PINB, PINB1)) // if LED on, turn off
            CLEARBIT(PORTB, PINB1);
         else                       // if LED off, turn on
            SETBIT(PORTB, PINB1);
      WAIT(100);
   } 
}


