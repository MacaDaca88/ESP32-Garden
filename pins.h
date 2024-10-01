#ifndef PINS_H
#define PINS_H


#ifdef __AVR__
#define BATT1 A0
#define BATT2 A1
#define BATT3 A2
#define BATT4 A3

#define DISCHARGE A7

#define LED 13

#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4


#define MOSI 9   // data
#define MISO 11  //dc
#define SCK 10   // clock
#define SS 12    // cs
#define RES 6    // res


#endif
#ifdef UNO
#warning "no A7 u dumb dumb"
#endif
///////////////////////////////////////////////ESP PINOUT///////////////////////////////////
#ifdef ESP32

#define SW1 26
#define SW2 25
#define SW3 33
#define SW4 32
#define SW5 35
#define SW6 34

#define LED 26

#define BUTTON1 15
#define BUTTON2 0
#define BUTTON3 4

#define DHTPIN 2  // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11  // DHT 11

/*SPI	
MOSI GPIO 23	// data
MISO GPIO 19	// dc
SCLK GPIO 18	// clock
CS GPIO 5     // cs
*/
#define RES 27  // res

#endif
#endif
