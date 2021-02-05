#include "msg/Parser.hpp"

#include "msg/msg/Sync.hpp"

#include <array>
#include <cassert>
#include <limits>

namespace PicoIO::SerialComm {

namespace {
constexpr struct MessageInfo {
  constexpr MessageInfo() {
    for (auto& s : sizes_) {
      s = NOT_REGISTERED;
    }

    register_fixed_size_message<Messages::Sync>();
  }

  template <typename T>
  constexpr void register_fixed_size_message() {
    sizes_[static_cast<size_t>(T::id)] = sizeof(T);
  }

  static constexpr size_t NOT_REGISTERED = std::numeric_limits<size_t>::max();

  std::array<size_t, static_cast<size_t>(MessageId::_MaxId) + 1> sizes_{};
} message_sizes;
}  // namespace

bool Parser::is_fixed_length(MessageId id) {
  return static_cast<uint8_t>(id) <=
         static_cast<uint8_t>(MessageId::_MaxFixedSize);
}

size_t Parser::get_fixed_length(MessageId id) {
  const size_t length = message_sizes.sizes_[static_cast<size_t>(id)];
  assert(length != MessageInfo::NOT_REGISTERED);
  return length;
}

}  // namespace PicoIO::SerialComm
