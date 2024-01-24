// GPIO0->GND(for upload)/3v3
// GPIO15->GND
// EN->3v3
// ADC -> KY-0.13

#include "Arduino.h"
#include <KY013.h>

KY013 thermistor(PIN_A0);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));

  int rawADC = analogRead(PIN_A0);
  Serial.print("rawADC: ");
  Serial.println(rawADC);

  float temp = thermistor.readTemperatureC();

  Serial.print("temp: ");
  Serial.print(temp);
  Serial.println(" C");

  delay(2000);
}