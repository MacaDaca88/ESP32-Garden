#ifndef SWITCH_H
#define SWITCH_H

int sw1 = 0;
int sw2 = 0;
int sw3 = 0;
int sw4 = 0;
int sw5 = 0;
int sw6 = 0;

void Plant() {
  u8g2.clearBuffer();

  u8g2.setDrawColor(0);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawBox(0, 0, 127, 63);

  u8g2.setDrawColor(1);
  u8g2.setCursor(50, 10);
  u8g2.print("N01");


  u8g2.setCursor(40, 30);
  u8g2.print("Type = ");
  //u8g2.print(planttype);
  u8g2.sendBuffer();
  return;
}


void Switch() {

  sw1 = digitalRead(SW1);
  sw2 = digitalRead(SW2);
  sw3 = digitalRead(SW3);
  sw4 = digitalRead(SW4);
  sw5 = digitalRead(SW5);
  sw6 = digitalRead(SW6);

  u8g2.setDrawColor(1);
  u8g2.drawBox(100, 50, 127, 63);
  if (sw1 == HIGH) {
    Plant();
    u8g2.setDrawColor(0);
    u8g2.drawBox(105, 52, 127, 61);
  }
  if (sw6 == HIGH) {
    State();
  }
}
#endif