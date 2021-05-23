#include <PubSubClient.h>

void subscribeRoutes(PubSubClient MQTT)
{
    MQTT.subscribe("door/open");
    MQTT.subscribe("door/close");
    MQTT.subscribe("door/get-state");
}