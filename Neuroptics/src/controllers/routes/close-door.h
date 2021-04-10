#include <string.h>
#include <Arduino.h>
#include "../definitions.h"

void closeDoor(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, "door/close") == 0 && digitalRead(RED_LED) == LOW)
    {

        if (digitalRead(GREEN_LED) == HIGH)
        {
            digitalWrite(GREEN_LED, LOW);
            digitalWrite(RED_LED, HIGH);
        }
        else
        {
            digitalWrite(RED_LED, HIGH);
        }

        Serial.println("Door CLOSED");
    }
}