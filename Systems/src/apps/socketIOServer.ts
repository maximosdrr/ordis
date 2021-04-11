import { Server } from "http";
import { MqttClient } from "mqtt";
import { Server as SocketServer } from "socket.io";
import { socketRoutes } from "../routes/socket-routes";

export class SocketIOServer {
  public io: SocketServer;

  constructor(server: Server) {
    this.io = new SocketServer(server, {
      cors: { allowedHeaders: "*" },
      allowEIO3: true,
    });
  }

  listen(mqttClient: MqttClient) {
    this.io.on("connection", (socket) => {
      console.log(`New Client Connected on SocketIo: ${socket.id}`);
    });

    socketRoutes(this.io, mqttClient);
  }
}
