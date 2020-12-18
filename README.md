
[![Arduino CI](https://github.com/RobTillaart/DAC8554/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/DAC8554/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/DAC8554.svg?maxAge=3600)](https://github.com/RobTillaart/DAC8554/releases)

# DAC8551

Arduino library for DAC8554 SPI Digital Analog Convertor

## Description

**Warning** not tested extensively

The DAC8551 is a SPI based 16 bit DAC with four channels.

## Interface

### Core

- **DAC8551(uint8_t slaveSelect)** Constructor for hardware SPI,
since 0.2.0 the slaveSelect pin needs to be defined.
- **DAC8551(uint8_t spiData, uint8_t spiClock, uint8_t slaveSelect)** Constructor for the software SPI
- **void begin()** initializes all pins to default state
- **void setValue(uint16_t value)** set the value of the channel to 0 - 65535
- **uint16_t getValue()** returns the last value written.

### Power down
check datasheet for details.

- **void setPowerDown(uint8_t powerDownMode)** sets power down mode. 0 - 3.
- **uint8_t getPowerDownMode()** returns last written mode.

| Power down mode         | Value |
|:------------------------|:-----:|
| DAC8554_POWERDOWN_NORMAL    | 0x00 |
| DAC8554_POWERDOWN_1K        | 0x40 |
| DAC8554_POWERDOWN_100K      | 0x80 |
| DAC8554_POWERDOWN_HIGH_IMP  | 0xC0 |



## Operation

See examples

**demo_hw_spi.ino**
- write a sawtooth to channel A followed by a sinus 
- uses HW SPI

**demo_sw_spi.ino**
- write a sawtooth to channel A followed by a sinus 
- uses SW SPI

**demo_same_time_write.ino**
- writes two square waves that trigger at the same time

**demo_sequential_write.ino**
- writes two square waves sequentially (slight time difference)

**demo_powerdown.ino**
- idem

## TODO

more testing
