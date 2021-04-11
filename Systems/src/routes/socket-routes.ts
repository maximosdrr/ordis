import { MqttClient } from "mqtt";
import { Server } from "socket.io";
import leds from "../controllers/Leds";

export const socketRoutes = (io: Server, mqttClient: MqttClient) => {
  io.on("connect", (socket) => {
    console.log("Ordis Systems has connected socketIO");
    // TODO ROUTES
    socket.on("door/open", (payload: string) =>
      leds.turnOnGreenLed(payload, mqttClient)
    );
    socket.on("door/close", (payload: string) =>
      leds.turnOnRedLed(payload, mqttClient)
    );

    // END ROUTES
  });
};
