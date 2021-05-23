import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { MqttBrokerServer } from './apps/broker';

async function bootstrap() {
  const broker = new MqttBrokerServer();
  broker.listen();
  const app = await NestFactory.create(AppModule);
  await app.listen(3000);
}
bootstrap();
