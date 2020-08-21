# AVR tutorial
Easy-to-grasp, step-by-step tutorials for creating firmware for the AVR family of microprocessors.

## Season 1, Lesson 4: Flasher

### What you'll need

1. Everything in [Lesson 1](01-01-LED-light.md) (you can also use the setup from a later lesson; we just won't be using a button for this).

Now let's do away with user input and let the processor do its own thing. Interrupts are used not only for making a system interactive; they can also handle timed events. In this lesson, we'll set up the chip's internal timer to fire off an interrupt periodically.

The ATMega88 by default runs at 1 MHz (1 million cycles/second) and has a simple internal oscillator (a.k.a. "clock") that we can play with. Projects that require precise timing use an external crystal or ceramic oscillator, which are cheap and easy to come by -- we may do something with that later. The internal clock is fine for our needs here.

### Setup
#### Hardware
1. Do everything in [Lesson 1](01-01-LED-light.md) or later.

#### Firmware
1. Download the code from [Code 01-04](../code/01-04.c) and save it to your AVR development directory. Take a look at the code. This one is also simple and commented; pay special attention to the interrupt handling.
1. Open a Terminal in the directory holding the code.
1. As in previous lessons, enter the following commands in order: 

   `avr-gcc -g -Os -mmcu=atmega88 -c 01-04.c`

   `avr-gcc -g -mmcu=atmega88 -o 01-04.elf 01-04.o`

   `avr-objcopy -j .text -j .data -O ihex 01-04.elf 01-04.hex`

   `sudo avrdude -c buspirate -P /dev/ttyUSB0 -p m88p -U flash:w:01-04.hex`

As soon as the firmware is finished being flashed, the LED should begin flashing -- toggling once per second.

### More about the firmware
To get interrupts working as a delay timer, we need to do a bit more prep work and introduce some new code. 

`cli();` disables all interrupts while we're making changes (*CL*ear *I*nterrupt)

`SETBIT(TCCR1B, CS11);` These two lines divide

`SETBIT(TCCR1B, CS10);` the chip's frequency by 64

`OCR1A = 15624;` gives a 1-second duration (1 MHz/64 - 1)

`SETBIT(TCCR1B, WGM12);` Puts Timer1 into Clear Timer on Compare (CTC) mode

`SETBIT(TIMSK1, OCIE1A);` Enables Timer1 Compare Match interrupt (TIMER1_COMPA_vect in code)

`sei();` enables all interrupts (*SE*t *I*nterrupt)



Now it's time to move on to the [next lesson](01-05-traffic-lights.md) (if not available yet, keep your eyes open)!

As always, please send questions, corrections, and/or snide remarks to xenloops at protonmail dot com or @xenloops on Twitter.

