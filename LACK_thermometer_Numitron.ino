/*
  OLED thermometer for IKEA LACK enclosure with a `Nixie` style font.
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


  // Clear the display
  display.clearDisplay();

  int temperature = sensors.getTempCByIndex(0) * 10;

  if (temperature > 0 and temperature < 1000 ) {

    int temperature_10 = temperature / 100;
    int temperature_1 = (temperature % 100) / 10;
    int temperature_0 = (temperature % 10);

    Serial.println(temperature);

    numitron(temperature_10, 0, 16);
    numitron(temperature_1, 1, 16);
    numitron(11, 2, 16);
    numitron(temperature_0, 3, 16);
    numitron(12, 4, 16);

  } else {

    numitron(10, 0, 16);
    numitron(10, 1, 16);
    numitron(11, 2, 16);
    numitron(10, 3, 16);
    numitron(12, 4, 16);
  }


  // Draw the display
  display.display();

}



void numitron(int numeral, int char_pos, int char_offset) {
  /*  Function to draw numitron sytle digits
      Additional Glyphs included:
      10  :
      11  .
      12  Degrees C
  */

  int pos = (char_pos * 22) + char_offset;

  switch (numeral) {

    case 0:
      // Draw 0
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(0 + pos, 16, 0 + pos, 30, SSD1306_WHITE);      // e
      display.drawLine(0 + pos, 1, 0 + pos, 14, SSD1306_WHITE);       // f
      break;


    case 1:
      // Draw 1
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      break;


    case 2:
      // Draw 2
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(0 + pos, 16, 0 + pos, 30, SSD1306_WHITE);      // e
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    case 3:
      // Draw 3
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;

    case 4:
      // Draw 4
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      display.drawLine(0 + pos, 1, 0 + pos, 14, SSD1306_WHITE);       // f
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    case 5:
      // Draw 5
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(0 + pos, 1, 0 + pos, 14, SSD1306_WHITE);       // f
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    case 6:
      // Draw 6
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(0 + pos, 16, 0 + pos, 30, SSD1306_WHITE);      // e
      display.drawLine(0 + pos, 1, 0 + pos, 14, SSD1306_WHITE);       // f
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    case 7:
      // Draw 7
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      break;


    case 8:
      // Draw 8
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(0 + pos, 16, 0 + pos, 30, SSD1306_WHITE);      // e
      display.drawLine(0 + pos, 1, 0 + pos, 14, SSD1306_WHITE);       // f
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    case 9:
      // Draw 9
      display.drawLine(2 + pos, 0, 14 + pos, 0, SSD1306_WHITE);       // a
      display.drawLine(16 + pos, 1, 16 + pos, 14, SSD1306_WHITE);     // b
      display.drawLine(16 + pos, 16, 16 + pos, 30, SSD1306_WHITE);    // c
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(0 + pos, 1, 0 + pos, 14, SSD1306_WHITE);       // f
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    case 10:
      // Draw -
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    case 11:
      // Draw .
      display.drawRoundRect(16 + pos, 30, 2, 2, 2, SSD1306_WHITE);
      break;


    case 12:
      // Draw Degrees C
      display.drawLine(2 + pos, 31, 14 + pos, 31, SSD1306_WHITE);     // d
      display.drawLine(0 + pos, 16, 0 + pos, 30, SSD1306_WHITE);      // e
      display.drawLine(2 + pos, 15, 14 + pos, 15, SSD1306_WHITE);     // g
      break;


    default:
      // Clear the screen is an invalid numeral is sent.
      display.clearDisplay();
      display.display();
      break;


  }
}
