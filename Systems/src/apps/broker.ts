import { Injectable } from '@nestjs/common';
import { Server } from 'mosca';

@Injectable()
export class MqttBrokerServer {
  private server: Server;
  constructor() {
    this.server = new Server({
      port: 1883,
      host: '10.0.0.107',
    });
  }

  listen() {
    this.server.on('ready', () => {
      console.log('[Broker]: Broker server up');
    });

    this.server.on('clientConnected', () => {
      console.log('[Broker]: New client connected');
    });
  }
}
