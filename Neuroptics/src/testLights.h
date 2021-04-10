#define GREEN_LED 4
#define RED_LED 5
#include <Arduino.h>

void testLigths()
{
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, HIGH);

    delay(5000);

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);

    delay(1000);
}