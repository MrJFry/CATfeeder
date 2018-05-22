# CATfeeder
Source Code for an ESP8266- powered cat feeder.

At the weekend it was a pain in the ass to get up feed my cat at 6am. 
So I built a more comfortable way to feed him with a click of a button on your smartphone while staing in bed ;-)

# Hardware

First of all you will need a 3D printer or the possibility tu use one.
I Used an Anet A8.
The needed STL- files can be found here:

->  www.thingiverse.com/thing:688807/

**Big thanks to odwdinc for sharing this awesome 3D Print!**

To build this you need the following parts:

- ESP8266 Module (I used this one: https://goo.gl/8yTebJ)
- 28BYJ-48 Stepper Motor
- ULN2003 Stepper Driver (I found motor and driver as a set on amazon for cheap: https://goo.gl/UivXvD)
- Some wires
- 5V USB power adapter
- Micro USB cable
- 3D printed STL-files from the 3D folder

## Hardware Setup

### Wiring
| ESP8266  | ULN2003|
| -------  | ---    |
| GPIO14   | IN1    |
| GPIO12   | IN2    |
| GPIO13   | IN3    |
| GPIO15   | IN4    |
| GPIO15   | IN4    |
| GND      |  -     |
| VCC      |  +     |

### 3D printed parts
Assemble the 3D prints for the cat feeder as shown on the pictures on www.thingiverse.com/thing:688807/.
Print the spacers for the stepper twice and glue the with loctite in the right position.
Print the adapter once and stick it on the feed2 part. 
For more stability you can also insert screws in the holes, but I don't needed them.
As a hopper I simply used a cleaned Arizona ice tea bottle and cut the bottom of.

As you can see on the pictures I glued everything together with duct tape to find the best angle for the nozzle but this is only for testing.
I recommend using loctite to glue the parts toghether.

# Software

To use this you have to install the latest arduino IDE and the following libs:

- <ESP8266> https://github.com/esp8266/Arduino
- <Stepper2.h> https://github.com/Samireltabal/Stepper2 

# How to?

Simply add your wifi name and password in the .ino script, flash it to the ESP8266 using the programming board and open the serial monitor.
The ESP8266 will print his own IP-address in the serial monitor.
Copy this address and replace every IPaddressofESP8266 in the .ino with the Ip-address.
Now you can open it with your webbrowser.

Have fun feeding your cat ;-)



