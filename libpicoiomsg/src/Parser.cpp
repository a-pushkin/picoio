#include "msg/Parser.hpp"

#include "msg/msg/Reset.hpp"

#include <array>
#include <cstddef>

namespace PicoIO::SerialComm {

namespace {
constexpr struct MessageInfo {
  constexpr MessageInfo() { register_fixed_size_message<Messages::Reset>(); }

  template <typename T>
  constexpr void register_fixed_size_message() {
    sizes_[static_cast<size_t>(T::id)] = sizeof(T);
  }

  std::array<size_t, static_cast<size_t>(MessageId::_MaxId) + 1> sizes_{};
} message_sizes;
}  // namespace

bool Parser::is_fixed_length(MessageId id) {
  return static_cast<uint8_t>(id) <=
         static_cast<uint8_t>(MessageId::_MaxFixedSize);
}

}  // namespace PicoIO::SerialComm
