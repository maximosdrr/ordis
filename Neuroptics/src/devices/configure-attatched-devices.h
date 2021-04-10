#include <Arduino.h>

#define PORT4 4
#define PORT5 5

void configureAttachedDevices()
{
    pinMode(PORT4, OUTPUT);
    pinMode(PORT5, OUTPUT);
}