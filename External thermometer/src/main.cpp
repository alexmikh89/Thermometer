// ```Pin connection reference```
// GPIO0->GND(for upload)/3v3(for execution)
// GPIO15->GND
// EN->3v3
// ADC -> KY-0.13 via devder: 'KY-0.13 pin' + 5k + 'ESP ADC pin' + 10k + GND

#include "Arduino.h"
#include <KY013.h>

KY013 thermistor(PIN_A0);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  float temp = thermistor.readTemperatureC();

  Serial.print("temp: ");
  Serial.print(temp);
  Serial.println(" C");

  delay(2000);
}