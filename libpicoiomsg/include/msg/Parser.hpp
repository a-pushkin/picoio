#pragma once

#include "msg/MessageIds.hpp"

#include <cstddef>

namespace PicoIO::SerialComm {
class Parser {
 public:
  static bool is_fixed_length(MessageId id);
  static size_t get_fixed_length(MessageId id);
};
}  // namespace PicoIO::SerialComm
