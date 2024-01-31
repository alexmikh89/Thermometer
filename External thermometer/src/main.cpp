// ```Pin connection reference```
// GPIO0->GND(for upload)/3v3(for execution)
// GPIO15->GND
// EN->3v3
// ADC -> KY-0.13 via devider: 'KY-0.13 pin' + 4k7 + 'ESP ADC pin' + 2k + GND

#include "Arduino.h"
#include <KY013.h>
#include "MUX74HC4067.h"

KY013 thermistor(PIN_A0);
MUX74HC4067 mux(12, 14, 0, 4, 5); // IO12 IO14 IO00 IO04 IO05 -> EN S0 S1 S2 S3

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  mux.signalPin(13, OUTPUT, DIGITAL); //  IO13 -> SIG
}

void loop()
{
  float temp = thermistor.readTemperatureC() - 19;
  Serial.print(temp);
  Serial.println(" C");
  delay(500);

  for (byte i = 0; i < 16; ++i)
  {
    mux.write(i, HIGH); // Connects to channel i and writes HIGH
    delay(50);
    mux.write(i, LOW); // Connects to channel i and writes LOW
    delay(50);
  }
}
