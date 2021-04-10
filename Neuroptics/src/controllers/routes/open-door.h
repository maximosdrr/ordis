#include <string.h>
#include <Arduino.h>
#include "../definitions.h"

void openDoor(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, "door/open") == 0 && digitalRead(GREEN_LED) == LOW)
    {
        if (digitalRead(RED_LED) == HIGH)
        {
            digitalWrite(RED_LED, LOW);
            digitalWrite(GREEN_LED, HIGH);
        }
        else
        {
            digitalWrite(GREEN_LED, HIGH);
        }

        Serial.println("Door Opened");
    }
}