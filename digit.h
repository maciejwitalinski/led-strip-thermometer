#include <Adafruit_NeoPixel.h>
#ifndef Digit_h
#define Digit_h

class Digit {
  public: 
    Digit(int _ledCount, int _pin);
    void begin();
    void test();
    void reset();
    void displayTop();
    void displayTopLeft();
    void displayTopRight();
    void displayBottom();
    void displayBottomLeft();
    void displayBottomRight();
    void displayCenter();
    void display(int num);
    void apply();
    int r;
    int g;
    int b;
  private:
    Adafruit_NeoPixel _pixels;
    byte *_ledCount;
    byte *_pin;
};

#endif
