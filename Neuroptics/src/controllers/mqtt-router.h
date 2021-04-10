#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <Arduino.h>
#include <string.h>

#include "routes/close-door.h"
#include "routes/open-door.h"

void mqttController(char *topic, byte *payload, unsigned int length)
{
    openDoor(topic, payload, length);
    closeDoor(topic, payload, length);
}