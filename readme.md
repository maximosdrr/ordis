# Ordis

An open source project that aims to create a controller for arduino extensions using the MQTT protocol, in addition we also created a broker server for mqtt where a socket.io interface is used for easy communication with devices of any type

## Getting Started

The first step to start the project is to go to the "Neuroptics/src" directory and create a file called "connection-config.h", inside it you will need to have a code similar to this one replacing the values with your personal settings

```c++
const char *SSID = "YOUR SSID"; //wifi name
const char *PASSWORD = "YOUR WIFI PASSWORD"; //wifi password
const char *MQTT_SERVER = "BROKER SERVER IP "; //broker server example: 10.0.0.000
const int MQTT_PORT = 3000; //broker port
```

Now we need to configure the .env file in the system part of ordis, first go to the "Systems" folder and inside it create a file called .env, inside it you should have a configuration similar to this one

```javascript
MQTT_PORT = YOUR_MQTT_PORT; //example: 3000
EXPRESS_PORT = YOUR_EXPRESS_PORT; //example: 3001
MQTT_HOST = "YOUR_MQTT_HOST"; //example: "mqtt://10.0.0.100"
BROKER_HOST = "YOUR_BROKER_HOST"; //example "10.0.0.100"
```

now to finish the process we just need to give an npm install or yarn to install the node_modules and the systems will be ready to run

```
npm install
```

npm run dev start the server

```
npm run dev
```

### Prerequisites

- **Commitzen:**

To standardize your commits I recommend using commitzen, it is easy to install and can be found here: [Commitzen](https://github.com/commitizen/cz-cli)

If you still don't have the commitzen installed globally on your machine, you should install it through npm or yarn

```
npm install commitizen -g
```

To perform the commit you must use:

```
git cz
```

- **Neuroptics:**
  To develop you will need to download the Platformio extension for your vscode, you will also need a nodemcu esp8266 or similar module to use the wifi connection features, in this version I am using two leds connected to a protoboard connected to ports 4 and 5, I am also using two resistors and three jumpers to connect to the board's leds and the gnd

- **Systems:**
  For the server, you need nodejs installed on your machine.

## Authors

- **Hiran Junior** - _Initial work_ - [Saga de Gêmeos](https://github.com/maximosdrr)

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/maximosdrr/ordis/blob/main/LICENSE) file for details

## Acknowledgments

- God
- Ordis Warframe
