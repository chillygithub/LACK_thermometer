/*
  OLED thermometer for IKEA LACK enclosure
  Uses a Dallas DS18B20 temperature sensor
  OLED display is 0.91 inch 128x32

  DS18B20 connections, with the flat side facing you
  Right   VDD   Pin 7
  Centre  DQ    Pin 2 4.7K ohm pull up resistor to Pin7
  Left    GND   GND


  
*/

// Import libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Declare Constants
#define ONE_WIRE_BUS 2  // Pin 2  DS18B20
#define OLED_RESET 4    // Pin 4  Reset pin for display
Adafruit_SSD1306 display(OLED_RESET);


// Initialise OnwWire
OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

void setup()   {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialise the Display at address 0x3C
  sensors.begin();  // Initialise the DS18B20

  // Pin 7 is used as power for the DS18B20 for easer wiring.
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

}


void loop() {


  // Request temperature
  sensors.requestTemperatures(); // Read temperatures from DS18B20


  // Refreah the display
  display.clearDisplay();

  // Display the temperature
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(8, 4);
  display.print(sensors.getTempCByIndex(0), 1);
  display.println("C");
  display.display();



}
