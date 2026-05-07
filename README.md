
[![Arduino CI](https://github.com/RobTillaart/A02YYUW/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/A02YYUW/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/A02YYUW/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/A02YYUW/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/A02YYUW/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/A02YYUW.svg)](https://github.com/RobTillaart/A02YYUW/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/A02YYUW/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/A02YYUW.svg?maxAge=3600)](https://github.com/RobTillaart/A02YYUW/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/A02YYUW.svg)](https://registry.platformio.org/libraries/robtillaart/A02YYUW)


# A02YYUW

Arduino library for A02YYUW Serial distance sensor.


## Description

**Experimental**

This library is to use the DFRobotics A02YYUW Serial distance sensor.

The A02YYUW has a range of 4.5 meter (15 feet) and it has an IP67 coating
so it can be used outdoors in almost all weather conditions.

Feedback as always is welcome.


### Hardware

The connector is a 4-pin JST-PH (2.0mm pitch) with the following pins.

|  colour  |  name  |  description      |  Notes  |
|:---------|:------:|:------------------|:-------:|
|  RED     |  VCC   |  power 3.3 - 5V   |
|  BLACK   |  GND   |  ground           |
|  WHITE   |  TX    |  transmit 3.3V    |  use voltage divider if needed.
|  YELLOW  |  RX    |  receive 3.3V     |

The device draws 8 mA average (see DFRobotic website).


### Related

- https://github.com/RobTillaart/SRF05 - distance sensor
- https://github.com/RobTillaart/US500 - US500 + US4000 underwater distance sensor.
- https://github.com/RobTillaart/lengthConverter
- https://github.com/RobTillaart/printHelpers - conversion.
- https://wiki.dfrobot.com/sen0311/docs/21654


### Tested

TODO: Test


## Interface

```cpp
#include "A02YYUW.h"
```

### Constructor

- **A02YYUW(Stream \* str)** Set the hardware serial port to use
- **void begin()** reset internals.


### Distance

- **bool newDistance()** workhorse, checks for new byte arrivals.
Syncs with the header byte so it knows which bytes to convert to 
a distance in millimetres. 
Returns true if a new distance is available.
Returns false otherwise.
- **uint16_t getDistanceMM()** returns the distance in millimetres.
- **float getDistanceCM()** returns the distance in centimetres.
- **float getDistanceINCH()** returns the distance in inches.
Uses decimal inches e.g. 4.2, does not use 1/8th or 1/16th.

### Control

- **uint32_t lastRead()** time in millis of last successful read.
- **void flush()** empties the input buffer of the Stream so next
value is a recent one.


## Future

#### Must

- improve documentation
- get hardware to test

#### Should

- add checksum check => error flag or just false?

#### Could

- create unit tests if possible

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


