export class Leds {
  turnOnGreenLed(payload: string, brokerClient: any) {
    console.log("called");
    brokerClient.publish("door/open", payload);
  }

  turnOnRedLed(payload: string, brokerClient: any) {
    console.log("called");
    brokerClient.publish("door/close", payload);
  }
}
