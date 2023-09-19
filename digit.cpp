#include <Adafruit_NeoPixel.h>
#include "Arduino.h"
#include "digit.h"

Digit::Digit(int ledCount, int pin) {
  _pixels = Adafruit_NeoPixel(ledCount, pin, NEO_GRB + NEO_KHZ800);
  _pixels.begin();
  _pin = pin;
  _ledCount = ledCount;
}

void Digit::begin() {
  _pixels.begin();  
}

void Digit::reset() {
  for (int i = 0; i < _ledCount; i++) {
    _pixels.setPixelColor(i, 0, 0, 0);
  }
}

void Digit::apply() {
  _pixels.show();  
}

void Digit::test() {
  for (int i = 0; i < _ledCount; i++) {
    _pixels.setPixelColor(i, 100, 100, 100);
  }
  _pixels.show();
}

void Digit::displayTopLeft() {
  for(int i = 0; i < 13; i++) {
    _pixels.setPixelColor(i, r, g, b);
  }
}

void Digit::displayTop() {
  for(int i = 0; i < 13; i++) {
    _pixels.setPixelColor(i + 13, r, g, b);
  }
}

void Digit::displayTopRight() {
  for(int i = 0; i < 13; i++) {
    _pixels.setPixelColor(i + 26, r, g, b);
  }
}

void Digit::Digit::displayBottomRight() {
  for(int i = 0; i < 13; i++) {
    _pixels.setPixelColor(i + 39, r, g, b);
  }
}

void Digit::displayBottom() {
  for(int i = 0; i < 13; i++) {
    _pixels.setPixelColor(i + 52, r, g, b);
  }
}

void Digit::displayBottomLeft() {
  for(int i = 0; i < 13; i++) {
    _pixels.setPixelColor(i + 65, r, g, b);
  }
}

void Digit::displayCenter() {
  for(int i = 0; i < 13; i++) {
    _pixels.setPixelColor(i + 78, r, g, b);
  }
}

void Digit::display(int num) {
  Digit::reset();
  switch(num) {
    case 0:
      displayTop();
      displayTopLeft();
      displayTopRight();
      displayBottomLeft();
      displayBottomRight();
      displayBottom();
      _pixels.show();
    break;

    case 1:
      displayTopRight();
      displayBottomRight();
      _pixels.show();
    break;

    case 2:
      displayTop();
      displayTopRight();
      displayCenter();
      displayBottomLeft();
      displayBottom();
      _pixels.show();
    break;

    case 3:
      displayTop();
      displayTopRight();
      displayCenter();
      displayBottomRight();
      displayBottom();
      _pixels.show();
    break;

    case 4:
      displayTopLeft();
      displayTopRight();
      displayCenter();
      displayBottomRight();
      _pixels.show();
    break;

    case 5:
      displayTop();
      displayTopLeft();
      displayCenter();
      displayBottomRight();
      displayBottom();
      _pixels.show();
    break;

    case 6:
      displayTop();
      displayTopLeft();
      displayCenter();
      displayBottomLeft();
      displayBottomRight();
      displayBottom();
      _pixels.show();
    break;

    case 7:
      displayTop();
      displayTopRight();
      displayBottomRight();
      _pixels.show();
    break;

    case 8:
      displayTop();
      displayTopLeft();
      displayTopRight();
      displayCenter();
      displayBottomLeft();
      displayBottomRight();
      displayBottom();
      _pixels.show();
    break;

    case 9:
      displayTop();
      displayTopLeft();
      displayTopRight();
      displayCenter();
      displayBottomRight();
      displayBottom();
      _pixels.show();
    break;
  }
}
