import mqtt from "mqtt";
import mosca, { Client, Server } from "mosca";
import { MqttClient } from "mqtt";
import { brokerSettings } from "../config";
import { Server as SocketServer } from "socket.io";
import { mqttRoutes } from "../routes/mqtt-routes";

export class MqttBrokerServer {
  private brokerServer: Server;
  public brokerClient: MqttClient;

  constructor(serverAddress: string, serverPort: number) {
    this.brokerServer = new mosca.Server(brokerSettings);
    this.brokerClient = mqtt.connect(serverAddress, {
      port: serverPort,
      clientId: `OrdisSystems${Math.random()}`,
    });

    this.brokerServer.on("ready", this.handleInitServer);
    this.brokerServer.on("clientConnected", this.handleClientConnection);
    this.brokerServer.on("clientDisconnected", this.handleDisconnection);
  }

  private handleClientConnection(client: Client) {
    console.log(`New Client Connected: ${client.id}`);
  }

  private handleInitServer() {
    console.log(`Broker Server Up`);
  }

  private handleDisconnection(client: Client) {
    console.log(`${client.id} Disconected`);
  }

  listen(socket: SocketServer) {
    mqttRoutes(this.brokerClient, socket);
  }
}
