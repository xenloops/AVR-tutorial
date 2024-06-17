# AVR-tutorial
Easy-to-grasp, step-by-step tutorials for creating firmware for the AVR family of microprocessors.

## Rationale

Many seasoned software engineers have the impression that writing and flashing firmware is "black magic" and tough to understand. This series of tutorials aims to deprogram that myth. Each "season" of the series will focus on one major topic. Each "episode" will cover one piece of each topic, building on previous episodes. This process will show anyone how simple it is to make a microprocessor do what you want.

## Lessons

[0. Set up lab: breadboard, AVR chip, BusPirate, AVR programmer, text editor](tutorials/00-00-lab-setup.md)

### Season 1: lighting and counting
1. [Light an LED: simple program to light LED programmatically.](tutorials/01-01-LED-light.md)
1. [Push a button to light an LED... pushbutton, then toggle.](tutorials/01-02-LED-button.md)
1. [Push a button to light an LED... by interrupt.](tutorials/01-03-LED-button-interrupt.md)
1. [Flasher: intro to timer and interrupts to flash an LED.](tutorials/01-04-LED-flasher.md)
1. [Fun with the timer and LEDs: traffic lights!](tutorials/01-05-traffic-lights.md)
1. [Dimming light: intro to PWM to pulsate an LED.](tutorials/01-06-LED-PWM-pulse.md) -- [Application Extra! LED candle](tutorials/01-06a-LED-candle.md)
1. Fun with a numeric LED: countdown, cycle around.
1. Combine button with LED counter and randomizer. LED shows numbers flashing by, when button pressed it stops on NEXT number generated.


## About the author

I've been fascinated by and have experimented in electronics since I was a kid. My parents gave me the famous "150-in-One Electronic Project Kit" from Radio Shack when I turned 10, and I couldn't stop inserting wires into spring clips in the cardboard base. Early in my software engineering career I had the good fortune to work at a consulting company with a number of bright and helpful electrical engineers, who designed and built the prototypes I would flash with firmware it was my job to craft. Atmel AVR chips were the first microprocessors I programmed, and I was hooked. Since then, programming a web site or application just hasn't held the same fascination. In the years since, I would reopen my "projects" boxes and fiddle with a breadboard and some components. Recently I did it again, and decided that it was time to infect others with my interest and fascination with this "dark art."

You can reach me at xenloops at protonmail dot com if you have ideas to try out here or questions.

Enjoy!
