#pragma once

#include "msg/MessageIds.hpp"

namespace PicoIO::SerialComm {
class Parser {
 public:
  static bool is_fixed_length(MessageId id);
};
}  // namespace PicoIO::SerialComm
