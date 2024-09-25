
#include <WiFi.h>

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
//#define UNO
#include "pins.h"

U8G2_SSD1305_128X64_ADAFRUIT_F_4W_SW_SPI u8g2(U8G2_R2, /* clock=*/SCK, /* data=*/MOSI, /* cs=*/SS, /* dc=*/MISO, /* reset=*/RES);

///////////////////////OTA//////////////////////////

#include "ota.h"

///////////////////////////////////////////////////


int button1 = 0;
int button2 = 0;
int button3 = 0;

int button1State = 0;
int button2State = 0;
int button3State = 0;

bool Home = false;
bool Wifi = false;


enum MenuState {
  HOME,
  WIFI
};

MenuState currentMenu = HOME;

int Time = 0;
int oldTime = 0;
int counter;
#include "wifiState.h"
#include "menu.h"


void setup() {
  u8g2.clearBuffer();
  Serial.begin(115200);
  OTAinit();
  dht.begin();
  sensor_t sensor;

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  pinMode(BATT1, INPUT);
  pinMode(BATT2, INPUT);
  pinMode(BATT3, INPUT);
  pinMode(BATT4, INPUT);

  pinMode(LED, OUTPUT);

  u8g2.begin();
  Serial.print("u8g2 BOOTING.");

  u8g2.setCursor(10, 10);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "u8g2 BOOTING.");
  u8g2.print(". ");
  u8g2.sendBuffer();
  delay(500);
}


void loop() {
  ArduinoOTA.handle();

  Time = millis();
  button1 = digitalRead(BUTTON1);
  button2 = digitalRead(BUTTON2);
  button3 = digitalRead(BUTTON3);


  if (button1 != button1State) {
    if (button1State == LOW) {
      counter++;
      Serial.print("counter");
      Serial.println(counter);

      switch (currentMenu) {
        case HOME:
          currentMenu = HOME;
          break;
        case WIFI:
          currentMenu = WIFI;
          break;
      }
    }
  }

  switch (currentMenu) {
    case HOME:
      home();
      Home = true;
      break;
    case WIFI:
      State();
      break;
  }
  button1State = button1;

  if (button2 != button2State) {
    if (button2State == LOW) {
    }
  }
  button2State = button2;
  if (button3 != button2State) {
    if (button3State == LOW) {
      State();
    }
  }
  button3State = button3;
}
