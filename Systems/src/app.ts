import express from "express";
import { createServer, Server } from "http";
import { Server as SocketServer } from "socket.io";
import * as mosca from "mosca";
import { Leds } from "./controllers/Leds";
import { moscaSettigns } from "./config/mosca-settings";
/* tslint:disable no-var-requires */
const mqtt = require("mqtt");

class App {
  public app: express.Application;
  public server: Server;
  public brokerServer: mosca.Server;
  private io: SocketServer;
  public PORT: number = 8100;
  public brokerClient: any;

  constructor() {
    this.routes();
    this.sockets();
    this.broker();
    this.listen();
  }

  routes() {
    this.app = express();
  }

  private broker(): void {
    this.brokerServer = new mosca.Server(moscaSettigns);
  }

  private sockets(): void {
    this.server = createServer(this.app);
    this.io = new SocketServer(this.server, {
      cors: { allowedHeaders: "*" },
      allowEIO3: true,
    });
  }

  private listen(): void {
    const leds = new Leds();
    const brokerClient = mqtt.connect("mqtt://10.0.0.107", { port: 3000 });

    this.brokerServer.on("clientConnected", () => {
      console.log("Novo cliente conectado ao broker");
    });

    this.io.on("connection", (socket) => {
      console.log("Novo cliente conectado ao socket");

      socket.on("door/open", (payload) =>
        leds.turnOnGreenLed(payload, brokerClient)
      );

      socket.on("door/close", (payload: string) =>
        leds.turnOnRedLed(payload, brokerClient)
      );

      socket.on("disconnect", () => {
        console.log("user disconnected");
      });
    });
  }
}

export default new App();
