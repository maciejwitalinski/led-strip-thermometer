#include "constants.h";
#include <OneWire.h>
#include "digit.h"
//#include <Adafruit_NeoPixel.h>/
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire onewire(ONEWIRE_PIN);
DallasTemperature sensors(&onewire);

int r = 50, g = 50, b = 50;

Digit digit1(LED_COUNT, DISPLAY_1_PIN);
Digit digit2(LED_COUNT, DISPLAY_2_PIN);
Digit digit3(LED_COUNT, DISPLAY_3_PIN);
const Adafruit_NeoPixel extra1 = Adafruit_NeoPixel(DISPLAY_EXTRA_1_LED_COUNT, DISPLAY_EXTRA_1_PIN, NEO_GRB + NEO_KHZ800);
const Adafruit_NeoPixel extra2 = Adafruit_NeoPixel(DISPLAY_EXTRA_2_LED_COUNT, DISPLAY_EXTRA_2_PIN, NEO_GRB + NEO_KHZ800);
const Adafruit_NeoPixel extra3 = Adafruit_NeoPixel(DISPLAY_EXTRA_3_LED_COUNT, DISPLAY_EXTRA_3_PIN, NEO_GRB + NEO_KHZ800);
const Adafruit_NeoPixel extra4 = Adafruit_NeoPixel(DISPLAY_EXTRA_4_LED_COUNT, DISPLAY_EXTRA_4_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  while(!Serial);
  Serial.begin(9600);
  sensors.begin();
  digit1.begin();
  digit2.begin();
  digit3.begin();
  extra1.begin();
  extra2.begin();
  extra3.begin();
  extra4.begin();
  displayExtras();
  digit1.test();
  digit2.test();
  digit3.test();
  delay(3000);
}
 
void loop() {
  sensors.requestTemperaturesByAddress(deviceAddress);
  float temp = sensors.getTempC(deviceAddress);
  const String tempStr = String(temp, 1);
  
  setColors(temp);
  displayExtras();
  digit1.r = r, digit1.g = g, digit1.b = b;
  digit2.r = r, digit2.g = g, digit2.b = b;
  digit3.r = r, digit3.g = g, digit3.b = b;
  
  if (temp >= 0 && temp < 10) {
    digit1.reset();
    digit1.apply();
    digit2.display(tempStr.substring(0,1).toInt());
    digit3.display(tempStr.substring(2,3).toInt());
    delay(2000);
  } else if (temp >= 10) {
    digit1.display(tempStr.substring(0,1).toInt());
    digit2.display(tempStr.substring(1,2).toInt());
    digit3.display(tempStr.substring(3,4).toInt());
    delay(2000);
  } else if (temp <= 0 && temp > -10) {
    digit1.reset();
    digit1.apply();
    digit2.display(tempStr.substring(1,2).toInt());
    digit3.display(tempStr.substring(3,4).toInt());
    delay(1000);
    digit2.reset();
    digit2.apply();
    digit3.reset();
    digit3.apply();
    delay(300);
  } else {
    digit1.display(tempStr.substring(1,2).toInt());
    digit2.display(tempStr.substring(2,3).toInt());
    digit3.display(tempStr.substring(4,5).toInt());
    delay(1000);
    digit1.reset();
    digit1.apply();
    digit2.reset();
    digit2.apply();
    digit3.reset();
    digit3.apply();
    delay(300);  
  }
}

void displayExtras() {
  for (int i = 0; i < DISPLAY_EXTRA_1_LED_COUNT; i++) {
    extra1.setPixelColor(i, r, g, b);
  }
  extra1.show();

  for (int i = 0; i < DISPLAY_EXTRA_2_LED_COUNT; i++) {
    extra2.setPixelColor(i, r, g, b);
  }

  extra2.show();

  for (int i = 0; i < DISPLAY_EXTRA_3_LED_COUNT; i++) {
    extra3.setPixelColor(i, r, g, b);
  }

  extra3.show();

  for (int i = 0; i < DISPLAY_EXTRA_4_LED_COUNT; i++) {
    extra4.setPixelColor(i, r, g, b);
  }

  extra4.show();
}

void setColors(int temp) {
  if (temp < 30) {
     r = 52;
     g = 228;
     b = 237;
  }
  
  if (temp >= 30 && temp < 36) {
     r = 251;
     g = 255;
     b = 0;
  }  

  if (temp >= 36 && temp < 39) {
     r = 255;
     g = 140;
     b = 0;
  }  

  if (temp >= 39) {
     r = 244;
     g = 6;
     b = 6;
  }
}
