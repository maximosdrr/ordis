// #include <PubSubClient.h>
// #include <WiFiClient.h>
// #include <ESP8266WiFi.h>

// const char *ssid = "Ponto Alto";
// const char *password = "2357111317";
// const char *mqttServer = "10.0.0.107";
// const int mqttPort = 3000;

// WiFiClient espClient;
// PubSubClient client(espClient);

// void callback(char *topic, byte *payload, unsigned int length)
// {

//     Serial.print("Message arrived in topic: ");
//     Serial.println(topic);

//     Serial.print("Message:");
//     for (int i = 0; i < length; i++)
//     {
//         Serial.print((char)payload[i]);
//     }

//     Serial.println();
//     Serial.println("-----------------------");
// }

// void setup()
// {

//     Serial.begin(9600);

//     WiFi.begin(ssid, password);

//     while (WiFi.status() != WL_CONNECTED)
//     {
//         delay(500);
//         Serial.println("Connecting to WiFi..");
//     }
//     Serial.println("Connected to the WiFi network");

//     client.setServer(mqttServer, mqttPort);
//     client.setCallback(callback);

//     while (!client.connected())
//     {
//         Serial.println("Connecting to MQTT...");

//         if (client.connect("ESP32Client"))
//         {

//             Serial.println("connected");
//         }
//         else
//         {

//             Serial.print("failed with state ");
//             Serial.print(client.state());
//             delay(2000);
//         }
//     }

//     client.subscribe("message");
// }

// void loop()
// {
//     client.loop();
// }