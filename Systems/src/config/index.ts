import dotenv from "dotenv";

dotenv.config();

export const brokerSettings: any = {
  port: parseInt(process.env.MQTT_PORT ? process.env.MQTT_PORT : "3000", 0),
  host: process.env.BROKER_HOST,
};
