#pragma once
//
//    FILE: A02YYUW.h
//  AUTHOR: Rob Tillaart
//    DATE: 2026-05*07
// VERSION: 0.1.0
// PURPOSE: Arduino library for A02YYUW serial distance sensor
//     URL: https://github.com/RobTillaart/A02YYUW


#include "Arduino.h"

#define A02YYUW_LIB_VERSION         (F("0.1.0"))


class A02YYUW
{
public:
  A02YYUW(Stream * str);

  void     begin();

  bool     newDistance();
  uint16_t getDistanceMM();
  float    getDistanceCM();
  float    getDistanceINCH();

  uint32_t lastRead();
  void     flush();

private:
  Stream * _stream;
  uint8_t  _byte;
  uint8_t  _high, _low;
  uint16_t _millimetres;   
  uint32_t _lastRead;   
};


//  -- END OF FILE --





