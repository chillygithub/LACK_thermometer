# LACK_thermometer

This is an Arduino based OLED thermometer for IKEA LACK enclosures made for 3D printers.


This project uses an Arduino Uno as it has an on-board voltage regulator that would accept the same 12 volt supply that I am using for the LED lighting. Other models such as the Nano and Micro will also work and can be powered from an USB supply.

The display is a slimline 0.91 inch 128 x 32 pixel OLED display. This is fixed into the display bezel using a small amount of epoxy resin from the rear.

Three version are available:
* LACK_thermometer: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Uses the native font from the library.
* LACK_thermometer_Nixie: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Uses a vector drawn Nixie style font. 
* LACK_thermometer_Numitron: &nbsp; &nbsp; Uses a vector drawn Numitron style font. 

Further details and 3D printed bezel are available from: https://www.prusaprinters.org/prints/41690-thermometer-for-lack-enclosure-arduino
