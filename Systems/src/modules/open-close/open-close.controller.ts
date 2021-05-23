import { Body, Controller, Post } from '@nestjs/common';
import { DoorState } from 'src/models/door-state';
import { OpenCloseService } from './open-close.service';

@Controller('open-close')
export class OpenCloseController {
  constructor(private readonly openCloseService: OpenCloseService) {}

  @Post('door/change-state')
  changeState(@Body() body: { door: number; state: DoorState }) {
    return this.openCloseService.changeState(body.door || 0, body.state);
  }
}
