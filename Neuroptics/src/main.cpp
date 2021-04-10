#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <Arduino.h>

#include "connectWifi.h"
#include "connectMqtt.h"
#include "testLights.h"

#define GREEN_LED 4
#define RED_LED 5

const char *SSID = "Ponto Alto";        //Seu SSID da Rede WIFI
const char *PASSWORD = "2357111317";    // A Senha da Rede WIFI
const char *MQTT_SERVER = "10.0.0.107"; //Broker do Mosquitto.org
const int MQTT_PORT = 3000;             //BROKER PORT

WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);

void connectMqtt()
{
  Serial.println("Connecting to MQTT...");

  if (MQTT.connect("ESP32Client"))
  {

    Serial.println("connected");
    MQTT.subscribe("door/open");
    MQTT.subscribe("door/close");
  }
  else
  {

    Serial.print("failed with state ");
    Serial.print(MQTT.state());
    delay(2000);
  }
}

void setup(void)
{
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  testLigths();

  digitalWrite(RED_LED, OUTPUT);

  connectWifi(SSID, PASSWORD);

  MQTT.setServer(MQTT_SERVER, MQTT_PORT);
  MQTT.setCallback(callback);

  while (!MQTT.connected())
  {
    connectMqtt();
  }
}

void loop(void)
{
  if (!MQTT.connected())
  {
    connectMqtt();
  }
  MQTT.loop();
}