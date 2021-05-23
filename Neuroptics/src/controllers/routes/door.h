#include <string.h>
#include <Arduino.h>
#include "../definitions.h"

#include <errno.h>

long getPortFromPayload(byte *payload, unsigned int length)
{
    char buffer[128];

    memcpy(buffer, payload, length);

    char *end = nullptr;
    long value = strtol(buffer, &end, 10);

    if (end == buffer || errno == ERANGE)
        return 0;
    else
        return value;
}

void change(char *topic, byte *payload, unsigned int length)
{
    if (strcmp(topic, "door/open") == 0)
    {
        long port = getPortFromPayload(payload, length);
        digitalWrite(port, HIGH);
    }

    if (strcmp(topic, "door/close") == 0)
    {
        long port = getPortFromPayload(payload, length);
        digitalWrite(port, LOW);
    }
}

// void getDoorState(char *topic, byte *payload, unsigned int length, PubSubClient MQTT)
// {
//     if (strcmp(topic, "door/get-state"))
//     {
//         long port = getPortFromPayload(payload, length);
//         int state = digitalRead(port);
//         MQTT.publish("door/state", (char *)state);
//     }
// }