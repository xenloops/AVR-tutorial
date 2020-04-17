/*
* AVR cybernetic display firmware
* written by: xenloops
* October 2019
*
* ATmega88PU
* 
* s01e01 -- You light up my life
* Simply light an LED using code.
* Prereq: LED on PB1.
*/

#include <avr/io.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

int main(void)
{
   // Setup I/O for the LED
   SETBIT(DDRB, PINB1);		//Set Port B Pin 1 to output

   SETBIT(PORTB, PINB1);   // turn on LED
   
   //Loop forever
   while(1) { } 
}


