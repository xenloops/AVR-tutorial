/*
* AVR cybernetic display firmware
* written by: Nathan Larson (@xenloops)
* November 2019
*
* ATmega88PU
* 
* s01e05 -- LED traffic lights
*/

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

// These do the same as SETBIT and CLEARBIT, but are conceptually clearer.
#define LEDOFF(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define LEDON(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))

#define R1 PIND5
#define Y1 PIND6
#define G1 PIND7
#define R2 PINB3
#define Y2 PINB2
#define G2 PINB1

#define WAIT(ms); _delay_ms(ms)

#define LONG 3000
#define SHORT 500

int main(void)
{
   // Setup I/O for the numeric LED
   // Set Ports B[1..3], D[5..7] to output
   // Set Ports  B[1..3], D[5..7] high to turn off LEDs
   SETBIT(DDRD, R1);
   SETBIT(PORTD, R1);
   SETBIT(DDRD, Y1);
   SETBIT(PORTD, Y1);
   SETBIT(DDRD, G1);
   SETBIT(PORTD, G1);
   SETBIT(DDRB, R2);
   SETBIT(PORTB, R2);
   SETBIT(DDRB, Y2);
   SETBIT(PORTB, Y2);
   SETBIT(DDRB, G2);
   SETBIT(PORTB, G2);
  
   //Initial setup: both reds on

   //Loop forever
   while(1) {
    /* 
     * We could do this with interrupts, but since it's the only thing the uC
     * needs to do, delays will be easier.
     * 
     * Sequence for (most) traffic lights in the U.S.:
     * R1 (SHORT) ------------------------------> G1 (LONG) Y1 (SHORT) R1 (SHORT) 
     * R2 (SHORT) G2 (LONG) Y2 (SHORT) R2 (SHORT) ------------------------------>:||
     */
    
    LEDON(PORTD, R1);
    LEDON(PORTB, R2);
    WAIT(SHORT);
    LEDOFF(PORTB, R2);
    LEDON(PORTB, G2);
    WAIT(LONG);
    LEDOFF(PORTB, G2);
    LEDON(PORTB, Y2);
    WAIT(SHORT);
    LEDOFF(PORTB, Y2);
    LEDON(PORTB, R2);
    WAIT(SHORT);
    LEDOFF(PORTD, R1);
    LEDON(PORTD, G1);
    WAIT(LONG);
    LEDOFF(PORTD, G1);
    LEDON(PORTD, Y1);
    WAIT(SHORT);
    LEDOFF(PORTD, Y1);
     
   } 
}




