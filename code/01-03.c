/*
* AVR cybernetic display firmware
* written by: Nathan Larson (@xenloops)
* November 2019
*
* ATmega88PU
* 
* s01e03 -- Knock knock
*        -- Who's there?
*        -- INTERRUPTING BUTTON
*        -- Interr--
*        -- CLICK!
* Push a button, momentarily light the LED -- using interrupts.
*/

#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define WAIT(ms); _delay_ms(ms)

#define LIGHT_MS 50      // How long light lit in ms

void initInt(void)
{
   // Setup the interrupt INT0 (PIN PD2)
   cli();                  // Disable interrupts
   SETBIT(EICRA, ISC00);
   SETBIT(EICRA, ISC01);   // INT0 rising edge generates IRQ
   SETBIT(EIMSK, INT0);    // Enable INT0
   sei();                  // Enable interrupts
}

ISR(INT0_vect)       // Interrupt Service Routine for INT0
{
   // Temporarily light LED
   SETBIT(PORTB, PINB1);
   WAIT(LIGHT_MS);
   CLEARBIT(PORTB, PINB1);
}

int main(void)
{
   // Setup I/O for the LED
   SETBIT(DDRB, PINB1);    // Set Port B Pin 1 to output
   CLEARBIT(PORTB, PINB1); // Set Port B Pin 1 low to turn off LED
   
   initInt();
   
   //Loop forever
   while(1) {
      // Do nothing; functionality handled by the interrupt!
   } 
}
