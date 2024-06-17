# AVR tutorial
Easy-to-grasp, step-by-step tutorials for creating firmware for the AVR family of microprocessors.

## Season 1, Lesson 6: Pulsing light

We've made a light that flashes on and off both by timer and command. But isn't it a tiny bit dissatisfying, only having a binary set of states, and no natural transition? This lesson rectifies that by igniting the LED gradually, then dimming it in the same fashion. You might have seen this technology used in electronic candles, which flicker an LED either randomly or using some complex pattern, mimicking a burning candle. This is how they do that.

At the core is a little piece of EE wizardrys called Pulse-Width Modulation (PWM). This quantizes the flow of electricity by chopping it into very fast discrete chunks. This can be used to control the apparent power running components like lights, stoves, amplifiers, and motors -- essential to fascinating projects like robotics (we'll get into that later). Each chunk makes up a circuit's duty cycle, comprising a powered part and an unpowered part. The greater fraction of the duty cycle is powered, the more the component is energized (e.g. a brighter bulb in this case).

Fortunately, most microcontrollers have a built-in way to control PWM, so you don't have to try to craft assembly code to do it.

### What you'll need

1. Everything in [Lesson 1](01-01-LED-light.md). Going back to the LED and resistor -- only this time we'll make the flashing light smoother.

### Setup
#### Hardware
1. Do everything in [Lesson 1](01-01-LED-light.md), except: change the LED and resistor part of the circuit such that the positive conductor on the LED is connected to the PD6 pin (pin 12 on the ATmega88) and the resistor connects once again between the negative conductor on the LED and the negative power rail. We do this to make PWM slightly easier, as we're only dealing with the 8-bit counter and registers. (The other PWMs on many AVRs involve 16-bit registers, which add a complexity we don't want here.)

#### Firmware
1. Download the code from [Code 01-06](../code/01-06.c) and save it to your AVR development directory. Take a look at the code, paying attention to the setup of the registers for PWM.
1. Open a Terminal in the directory holding the code.
1. As in previous lessons, enter the following commands in order: 

   `avr-gcc -g -Os -mmcu=atmega88 -c 01-06.c`

   `avr-gcc -g -mmcu=atmega88 -o 01-06.elf 01-06.o`

   `avr-objcopy -j .text -j .data -O ihex 01-06.elf 01-06.hex`

   `sudo avrdude -c buspirate -P /dev/ttyUSB0 -p m88p -U flash:w:01-06.hex`

As soon as the firmware is finished being flashed, the LED should begin pulsing much smoother than before. Nice, eh?

### More about the firmware
The settings for the PWM duty cycle are set up as preprocessor constants early in the code. Play with the values, see what happens.

Now it's time to move on to the [next lesson](01-06a-LED-candle.md) (if not available yet, keep your eyes open)!

As always, please send questions, corrections, and/or snide remarks to xenloops at protonmail dot com.

