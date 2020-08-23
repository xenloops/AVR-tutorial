# AVR tutorial
Easy-to-grasp, step-by-step tutorials for creating firmware for the AVR family of microprocessors.

## Application Extra! LED candle

Besides creating a more pleasing control panel for the Batmobile, what can we do with PWM? Some cool stuff. My favorite would be driving a DC motor, which will lead us to robotics. But not quite yet. We can also create Switching Mode Power Supplies (SMPS), but that doesn't turn my dial.

A few years ago, I bought a couple of electronic candles. (Wanted something that would give the impression of a candle, without the risk of a kid or dog knocking over an open flame.) Still not that impressed with e-candles, but upon seeing the flickering LED I immediately knew how they did it: randomized PWM.

That's what you'll do here. The idea is the same as in Lesson 6, but rather than set the LED to brighten to a specific level, then dim to a specific level, you'll change it to brighten to a random level, then dim to another lower random level, and repeat endlessly. That's really all an e-candle does.

C is a great language (many disagree, but the haters don't know what's good for them). It includes a basic pseudo-random number function (there are better ones as well, but this is a candle; how much thought do you really want to put into it?):

   `rand()`
   
rand() returns an integer between 0 and the C constant RAND_MAX (which depends on the hardware, but don't worry about that; it's stupendously large enough for our needs here). The basic usage to assign a random number to a variable in the range [min, max] is:

   `number = rand() % (max - min + 1) + min;`
   
where % is the modulo function, which just gives the remainder after division.

### What you'll need

1. Everything in [Lesson 6](01-06-LED-PWM-pulse.md).

### Setup
#### Hardware
1. Do everything in [Lesson 6](01-06-LED-PWM-pulse.md).

#### Firmware
1. Make a copy of your code from Lesson 6.
1. Modify the code so that two random numbers get set each time through the `while` loop. The maximum brightness is some value between 0 and MAX, and the minimum brightness is some number between 0 and the maximum brightness for that iteration.
1. Try it out! Best way to learn this is to play with the code. Try different ideas, see what works best for your tastes.

If you want to see what I did:

1. Download the code from [Code 01-06a](code/01-06a.c) and save it to your AVR development directory. Take a look at the choices I made for this.
1. Open a Terminal in the directory holding the code.
1. As in previous lessons, enter the following commands in order: 

   `avr-gcc -g -Os -mmcu=atmega88 -c 01-06a.c`

   `avr-gcc -g -mmcu=atmega88 -o 01-06a.elf 01-06a.o`

   `avr-objcopy -j .text -j .data -O ihex 01-06a.elf 01-06a.hex`

   `sudo avrdude -c buspirate -P /dev/ttyUSB0 -p m88p -U flash:w:01-06a.hex`

As soon as the firmware is finished being flashed, the LED should begin pulsing smoothly like a candle.

Now it's time to move on to the [next lesson](01-07.md) (if not available yet, keep your eyes open)!

As always, please send questions, corrections, and/or snide remarks to xenloops at protonmail dot com or @xenloops on Twitter.

