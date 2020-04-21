/*
* AVR cybernetic display firmware
* written by: Nathan Larson (@xenloops)
* November 2019
*
* ATmega88PU
* 
* s01e02 -- A more enlightened LED
* Push a button, light the LED -- via the uC.
*/

#include <avr/io.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

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
      {
         SETBIT(PORTB, PINB1);    // Temporarily light LED
         CLEARBIT(PORTB, PINB1);
      }
   } 
}


