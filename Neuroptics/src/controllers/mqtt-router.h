#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <Arduino.h>
#include <string.h>

#include "routes/door.h"

void mqttController(char *topic, byte *payload, unsigned int length)
{
    change(topic, payload, length);
    // getDoorState(topic, payload, length, MQTT);
}