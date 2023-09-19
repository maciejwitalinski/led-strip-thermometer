 #ifndef CONSTANTS_H
#define CONSTANTS_H
#include <DallasTemperature.h>

const int DISPLAY_1_PIN = 3;
const int DISPLAY_2_PIN = 4;
const int DISPLAY_3_PIN = 5;
const int LED_COUNT = 91;
const int INTERVAL = 1000;
const byte ONEWIRE_PIN = 2;
DeviceAddress deviceAddress = {0x28, 0x79, 0x27, 0x76, 0xE0, 0x01, 0x3C, 0x06};

const int DISPLAY_EXTRA_1_PIN = 6;
const int DISPLAY_EXTRA_1_LED_COUNT = 30;
const int DISPLAY_EXTRA_2_PIN = 7;
const int DISPLAY_EXTRA_2_LED_COUNT = 30;
const int DISPLAY_EXTRA_3_PIN = 8;
const int DISPLAY_EXTRA_3_LED_COUNT = 52;
const int DISPLAY_EXTRA_4_PIN = 9;
const int DISPLAY_EXTRA_4_LED_COUNT = 5;

#endif
