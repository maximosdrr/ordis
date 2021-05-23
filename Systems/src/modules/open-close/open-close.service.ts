import { BadRequestException, Injectable, Post } from '@nestjs/common';
import { BrokerClient } from 'src/apps/client';
import { DoorState } from 'src/models/door-state';

@Injectable()
export class OpenCloseService {
  constructor(private readonly brokerClient: BrokerClient) {}

  changeState(door: number, state: DoorState) {
    try {
      this.brokerClient.client.publish(
        state == DoorState.open ? 'door/open' : 'door/close',
        `${door}`,
      );
    } catch (e) {
      throw new BadRequestException('Bad request');
    }
  }
}
