import { Module } from '@nestjs/common';
import { BrokerClient } from './apps/client';
import { OpenCloseModule } from './modules/open-close/open-close.module';

@Module({
  imports: [OpenCloseModule],
  controllers: [],
  providers: [],
})
export class AppModule {}
