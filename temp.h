#ifndef TEMP_H
#define TEMP_H

DHT_Unified dht(DHTPIN, DHTTYPE);


float temp;
float humid;

float _temp;
float _humid;


void temps() {

  sensors_event_t event;

  dht.temperature().getEvent(&event);
  temp = event.temperature - 5;

  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  } else {
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawBox(0, 20, 127, 63);
    u8g2.setDrawColor(0);
    u8g2.setCursor(40, 30);
    u8g2.print("Temp = ");
    u8g2.print(temp);

    if (temp != _temp) {
      Serial.print("Temperature:");
      Serial.println(temp);
      _temp = temp;
    }
  }

  dht.humidity().getEvent(&event);
  humid = event.relative_humidity;

  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  } else {
    u8g2.setCursor(40, 50);
    u8g2.print("Humid = ");
    u8g2.print(humid);

    u8g2.sendBuffer();
    if (humid != _humid) {
      Serial.print("Humidity:");
      Serial.println(humid);
      _humid = humid;
    }
  }
  delay(500);

}
#endif