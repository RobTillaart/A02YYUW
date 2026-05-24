//
//    FILE: A02YYM_PWM_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test code for a A02YY "PWM" device
//          does not use the library.
//     URL: https://github.com/RobTillaart/A02YYUW
//          https://www.dypcn.com/uploads/A02-Output-Interfaces.pdf


#include "Arduino.h"


uint8_t RX = 4;
uint8_t TX = 3;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  //  Serial.print("A02YYUW_LIB_VERSION: ");
  //  Serial.println(A02YYUW_LIB_VERSION);
  Serial.println();

  pinMode(RX, OUTPUT);
  digitalWrite(RX, HIGH);
  pinMode(TX, INPUT);
  //  wait for TX LOW
  while (digitalRead(TX) == HIGH);
}


void loop()
{
  digitalWrite(RX, LOW);
  delay(5);
  digitalWrite(RX, HIGH);

  while (digitalRead(TX) == LOW);
  uint32_t start = micros();
  while (digitalRead(TX) == HIGH);
  uint32_t stop = micros();

  uint32_t duration = stop - start;
  float centimetres = duration / 57.5;

  Serial.print(millis());
  Serial.print("\t");
  Serial.println(centimetres, 1);

  delay(1000);
}


//  -- END OF FILE --
