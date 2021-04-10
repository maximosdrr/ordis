#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <Arduino.h>
#include <string.h>

#define GREEN_LED 4
#define RED_LED 5

void callback(char *topic, byte *payload, unsigned int length)
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
