class Leds {
  turnOnGreenLed(payload: string, brokerClient: any) {
    brokerClient.publish("door/open", payload);
  }

  turnOnRedLed(payload: string, brokerClient: any) {
    brokerClient.publish("door/close", payload);
  }
}

export default new Leds();
