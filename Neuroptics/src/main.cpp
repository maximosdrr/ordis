#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <Arduino.h>

#include "./connection-config.h"
#include "connections/connect-wifi.h"
#include "connections/connect-mqtt.h"
#include "devices/configure-attatched-devices.h"

void setup(void)
{
  Serial.begin(9600);
  configureAttachedDevices();
  connectWifi(SSID, PASSWORD);
  connectMqtt(MQTT_SERVER, MQTT_PORT);
}

void loop(void)
{
  if (!MQTT.connected())
  {
    connectMqtt(MQTT_SERVER, MQTT_PORT);
  }
  MQTT.loop();
}