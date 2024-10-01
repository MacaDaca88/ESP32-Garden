#ifndef MENU_H
#define MENU_H

#include "temp.h"
#include "switch.h"

void home() {



  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setDrawColor(0);
  u8g2.drawBox(0, 0, 127, 63);
  u8g2.setDrawColor(1);
  u8g2.setCursor(10, 10);
  u8g2.print("Auto Garden");
  u8g2.sendBuffer();
  temps();  // update temp and himidity
  Switch();
 // delay(500);
}

#endif
