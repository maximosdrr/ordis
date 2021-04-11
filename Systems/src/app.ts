import express from "express";
import { Server, createServer } from "http";
import { MqttBrokerServer } from "./apps/mqttBrokerServer";
import { SocketIOServer } from "./apps/socketIOServer";
import dotenv from "dotenv";

class App {
  public app: express.Application;
  public server: Server;

  constructor() {
    dotenv.config();
    this.routes();
    this.server = createServer(this.app);
    this.up();
  }

  private routes() {
    this.app = express();
  }

  up() {
    const socketIoServer = new SocketIOServer(this.server);
    const brokerServer = new MqttBrokerServer(
      process.env.MQTT_HOST ?? "mqtt://127.0.0.1",
      process.env.MQTT_PORT ? parseInt(process.env.MQTT_PORT, 0) : 3000
    );

    socketIoServer.listen(brokerServer.brokerClient);
    brokerServer.listen(socketIoServer.io);
  }
}

export default App;
