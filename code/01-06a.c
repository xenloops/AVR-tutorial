/*
* AVR cybernetic display firmware
* written by: Nathan Larson (@xenloops)
* Aug 2020
*
* ATmega88PU
* 
* s01e06a -- Create an LED candle effect by randomly using Pulse Wave Modulation (PWM)
*/

#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define WAIT(ms); _delay_ms(ms)

#define MAX 80
#define MIN 0
#define DELAY 4
#define SETPWM(duty) (OCR0A = duty)
/******************************************************************
Sets the duty cycle of output. 

Arguments
---------
duty = 0 - 255 (0% - 100%, respectively)

Function sets the duty cycle of pwm output generated on OC0 PIN
The average voltage on this output pin will be

         duty
 Vout=  ------ x 5v
	      255 

This can be used to control the brightness of LED or Speed of Motor.
*********************************************************************/

int main(void)
{
   /*
      Initialize PWM for ATmega88:
      TCCR0A/B - Timer Counter Control Registers
      Settings for:
      Timer Clock = CPU Clock (No Prescaling)
      Mode        = Fast PWM
      PWM Output  = Non Inverted
      -----------------------------------------------
      BITS DESCRIPTION
      TCCR0A:
      Clear OC0A on Compare Match 
      BIT 7 : COM0A1  Compare Output Mode = 1
      BIT 6 : COM0A0  Compare Output Mode = 0
      BIT 1 : WGM01  Wave form generartion mode = 1
      BIT 0 : WGM00  Wave form generartion mode = 1
      TCCR0B:
      BIT 3 : WGM02  Wave form generation mode = 0
      BIT 2 : CS02   Clock Select = 0
      BIT 1 : CS01   Clock Select = 0
      BIT 0 : CS00   Clock Select = 1
   */
   
	SETBIT(TCCR0A, WGM00);
   SETBIT(TCCR0A, WGM01);
   SETBIT(TCCR0A, COM0A1);
	SETBIT(TCCR0B, CS00);
	//Set OC0A PIN as output. It is PD6 on ATmega88
	SETBIT(DDRD, PD6);

   char brightness=0;
   char rndtop=0;
   char rndbtm=0;

   //Loop forever
   while(1) {
      rndtop=rand() % MAX;
      rndbtm=rand() % rndtop;
		// Loop with increasing brightness
		for(brightness = rndbtm; brightness < rndtop; brightness++)
		{
			SETPWM(brightness);
			WAIT(DELAY);
		}

		// Loop with decreasing brightness
		for(brightness = rndtop; brightness > rndbtm; brightness--)
		{
			SETPWM(brightness);
			WAIT(DELAY);
		}
   } 
}



