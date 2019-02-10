# CATfeeder
Source Code for an ESP8266- powered cat feeder.

At the weekend it was a pain in the ass to get up feed my cat at 6am. 
So I built a more comfortable way to feed him with a click of a button on your smartphone while staying in bed ;-)

# Hardware

First of all you will need a 3D printer or the possibility tu use one.
I Used an Anet A8.
The needed STL- files can be found here:

->  www.thingiverse.com/thing:688807/

**Big thanks to odwdinc for sharing this awesome 3D Print!**

To build this you need the following parts:

- ESP8266 Module (I used this one: https://goo.gl/8yTebJ)
- Some wires
- 5V USB power adapter
- Micro USB cable
- 3D printed STL-files from the 3D folder

For the 28BYJ-48 Motor:
- 28BYJ-48 Stepper Motor
- ULN2003 Stepper Driver (I found motor and driver as a set on amazon for cheap: https://goo.gl/UivXvD)

For the NEMA17 Motor
- NEMA 17 Stepper Motor (https://www.amazon.de/Longruner-Stepper-Verbinder-Montagehalterung-LD08/dp/B07FKH52S5/ref=sr_1_2_sspa?s=industrial&ie=UTF8&qid=1549824714&sr=1-2-spons&keywords=nema+17&psc=1)

- A4988 Stepper Motor Driver (https://www.amazon.de/Longruner-Stepstick-Stepper-Driver-Printer/dp/B071P41ZBW/ref=sr_1_1?s=industrial&ie=UTF8&qid=1549824766&sr=1-1&keywords=a4988&th=1)


## Hardware Setup

### Wiring

ULN2003:

| ESP8266  | ULN2003|
| -------  | ---    |
| GPIO14   | IN1    |
| GPIO12   | IN2    |
| GPIO13   | IN3    |
| GPIO15   | IN4    |
| GND      |  -     |
| VCC      |  +     |

NEMA17:

| ESP8266  |  A4988   | NEMA17  |
| -------  | -------- | ------- |
| GPIO14   | DIRECTION|   -     |
| GPIO12   | STEP     |   -     |
| GPIO16   | /ENABLE  |   -     |
| GPIO15   | IN4      |   -     |
| GND      |  MS1     |   -     |
| GND      |  MS2     |   -     |
| GND      |  MS3     |   -     |
|  -       |  2B      |   2B    |
|  -       |  2A      |   2A    |
|  -       |  1A      |   1A    |
|  -       |  1B      |   1B    |
| GND      |  GND     |    -    |
| +12V     |  VMOT    |    -    |
| GND      |  GND     |    -    |
| +5V      |  VDD     |    -    |

Bridge between /RESET and /SLEEP.
MS1 /MS2 /MS3 is configurated to full step.

### 3D printed parts
Assemble the 3D prints for the cat feeder as shown on the pictures on www.thingiverse.com/thing:688807/.
Print the spacers for the stepper twice and glue the with loctite in the right position.
Print the adapter once and stick it on the feed2 part. 
For more stability you can also insert screws in the holes, but I don't needed them.
As a hopper I simply used a cleaned Arizona ice tea bottle and cut the bottom of.

As you can see on the pictures I glued everything together with duct tape to find the best angle for the nozzle but this is only for testing.
I recommend using loctite to glue the parts toghether.

For the NEMA17 you will need another stepper motor mount, wich I will upload later.

# Software

To use this you have to install the latest arduino IDE and the following libs:

- ESP8266:  https://github.com/esp8266/Arduino
- Stepper2: https://github.com/Samireltabal/Stepper2 

# How to?

Simply add your wifi name and password in the .ino script, flash it to the ESP8266 using the programming board and open the serial monitor.
The ESP8266 will print his own IP-address in the serial monitor.
Copy this address and replace every IPaddressofESP8266 in the .ino with the Ip-address(only in the 28BYJ-48 version. ).
Now you can open it with your webbrowser.

Have fun feeding your cat ;-)



