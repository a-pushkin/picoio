#pragma once

#include <cstdint>

namespace PicoIO::SerialComm {

enum class MessageId : uint8_t {
  Reset = 0x00,
  SetPinMode = 0x01,

  _MaxFixedSize = 0x7f,
  _MaxId = 0xfe
};

}
