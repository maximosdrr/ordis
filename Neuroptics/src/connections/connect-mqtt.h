#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <Arduino.h>
#include <string.h>
#include <WiFiClient.h>

#include "controllers/mqtt-router.h"
#include "controllers/mqtt-subscriber.h"

WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);

void connectMqtt(const char *MQTT_SERVER, int MQTT_PORT)
{

    Serial.println("Connecting to MQTT...");

    MQTT.setServer(MQTT_SERVER, MQTT_PORT);
    MQTT.setCallback(mqttController);

    while (!MQTT.connected())
    {
        Serial.println("Try to connect MQTT...");

        if (MQTT.connect("ESP32Client"))
        {

            Serial.println("connected");
            subscribeRoutes(MQTT);
        }
        else
        {

            Serial.print("failed with state ");
            Serial.print(MQTT.state());
            delay(2000);
        }
    };
}
