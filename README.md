# PicoIO

PicoIO allows controlling GPIO pins and SPI controllers on RP2040 via USB or
UART. This allows adding GPIO and SPI functionality to any device that has 
serial or USB port.

PicoIO consists of:
* firmware for RP2040 that translates between serial commands and IO.
* C++ library that implements the serial protocol.
* Command line client.

## Serial protocol

Communication between firmware and client consists of messages.
Each message starts with uint8_t message id.
It is followed by optional message-specific content.
Content can be variable or fixed length.
Fixed length content has message IDs from range 0x00..0x7f.
Variable length content has message IDs from range 0x80..0xfe.
Variable length content starts with uint8_t content length.
Message ID 0xff is reserved for future extensibility.
