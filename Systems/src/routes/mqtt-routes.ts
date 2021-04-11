import { MqttClient } from "mqtt";
import { Server as SocketServer } from "socket.io";

export const mqttRoutes = (mqttClient: MqttClient, socket: SocketServer) => {
  mqttClient.on("message", (topic: string, payload: string) => {
    // TODO;
  });
};
