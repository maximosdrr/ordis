import { Injectable } from '@nestjs/common';
import * as mqtt from 'mqtt';
import { Client } from 'mqtt';

@Injectable()
export class BrokerClient {
  public client: Client;

  constructor() {
    this.client = mqtt.connect('mqtt://10.0.0.107', {
      port: 1883,
      clientId: `Systems_${Math.random()}`,
    });
  }
}
