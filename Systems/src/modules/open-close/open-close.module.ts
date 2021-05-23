import { Module } from '@nestjs/common';
import { OpenCloseService } from './open-close.service';
import { OpenCloseController } from './open-close.controller';
import { BrokerClient } from 'src/apps/client';

@Module({
  providers: [OpenCloseService, BrokerClient],
  controllers: [OpenCloseController],
})
export class OpenCloseModule {}
