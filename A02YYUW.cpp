//
//    FILE: A02YYUW.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2026-05-07
// VERSION: 0.1.0
// PURPOSE: Arduino library for A02YYUW serial distance sensor
//     URL: https://github.com/RobTillaart/A02YYUW



#include "A02YYUW.h"


A02YYUW::A02YYUW(Stream * str)
{
  _stream   = str;
  _byte     = 0;
  _lastRead = 0;
  _millimetres = 0;
}


void A02YYUW::begin()
{
  //  reset variables
  _byte = 0;
  _lastRead = 0;
  _millimetres = 0;
  //  empty the stream buffer.
  flush();
}


bool A02YYUW::newDistance()
{
  //  need to read 4 bytes from the stream starting
  //  packet == [0xFF header, high, low, checksum]
  while (_stream->available())
  {
    uint8_t data = _stream->read();
    if ((_byte == 0) && (data == 0xFF)) _byte++;
    else if (_byte == 1) { _byte++; _high = data; }
    else if (_byte == 2) { _byte++; _low = data;  }
    else if (_byte == 3)
    {
      //  test checksum (TODO)
      //  ?? error flag?
      //  if (_high + _low + 0xFF) == data)  ...
      //  if (_high + _low) == ++data)  ...

      //  distance in millimetres.
      _millimetres = _high * 256 + _low;
      _lastRead = millis();
      _byte = 0;
      return true;
    }
  }
  return false;
}


uint16_t A02YYUW::getDistanceMM()
{
  return _millimetres;
}


float A02YYUW::getDistanceCM()
{
  return _millimetres * 0.1;
}


float A02YYUW::getDistanceINCH()
{
  return _millimetres * (1.0 / 25.4);  //  0.0393700787
}


uint32_t A02YYUW::lastRead()
{
  return _lastRead;
}


void A02YYUW::flush()
{
  while (_stream->available()) _stream->read();
}


//  -- END OF FILE --

