#pragma once
//
//    FILE: DAC8554.h
//  AUTHOR: Rob Tillaart
// PURPOSE: Arduino library for DAC8554 SPI Digital Analog Convertor  
// VERSION: 0.1.3  experimental
// HISTORY: See DAC8554.cpp
//     URL: https://github.com/RobTillaart/DAC8552
//

#include <SPI.h>

#define DAC8554_POWERDOWN_NORMAL   0x00
#define DAC8554_POWERDOWN_1K       0x40
#define DAC8554_POWERDOWN_100K     0x80
#define DAC8554_POWERDOWN_HIGH_IMP 0xC0

#define DAC8554_LIB_VERSION "0.1.3"

class DAC8554
{
public:
  // hardware SPI constructor
  DAC8554(uint8_t address = 0);  // address is 0,1,2,3

  // software SPI constructor
  DAC8554(uint8_t spiData, uint8_t spiClock, uint8_t slaveSelect, uint8_t address = 0);

  void begin();

  void bufferValue(uint8_t DAC, uint16_t value);
  void setValue(uint8_t DAC, uint16_t value);
  //writes the value to the DAC but does not affect buffered ones
  void setSingleValue(uint8_t DAC, uint16_t value);

  void bufferPowerDown(uint8_t DAC, uint8_t powerDownMode);
  void setPowerDown(uint8_t DAC, uint8_t powerDownMode);
  void setSinglePowerDown(uint8_t DAC, uint8_t powerDownMode);

  // write all buffers to all(up to 4) 8554's DAC's
  void broadcastBuffer();
  // write value to all(up to 4) 8554's DAC's
  void broadcastValue(uint16_t value);
  // write powerDownMode to all 8554's DAC's
  void broadcastPowerDown(uint8_t powerDownMode);

private:
  uint8_t _spiData;
  uint8_t _spiClock;
  uint8_t _slaveSelect;
  uint8_t _address;
  bool    _hwSPI;

  void writeDevice(uint8_t configRegister, uint16_t value);
  void swSPI_transfer(uint8_t value);
};

// -- END OF FILE --
