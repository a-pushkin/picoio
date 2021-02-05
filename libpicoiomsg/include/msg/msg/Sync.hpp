#pragma once

#include "msg/MessageIds.hpp"

#include <array>

namespace PicoIO::SerialComm::Messages {
/**
 * @brief Reset request and response.
 *
 * Synchronizes communication protocol. Can be used to recover communication if
 * data was lost or corrupted.
 *
 * Whenever receiving size detects reset_token_value (which was randonly
 * generated) within receive buffer and prefixed by MessageId::Reset, it is
 * required to drop all previous data and partially parsed messages, start
 * parsing from this point and respond with identical Reset message.
 */
struct Sync {
  static constexpr MessageId id = MessageId::Sync;

  static constexpr std::array<uint8_t, 16> sync_token_value{
      {0x7d, 0xe2, 0x4b, 0xf8, 0x94, 0x21, 0x4c, 0xfb, 0xa2, 0xf7, 0x9a, 0x2e,
       0xb3, 0x0e, 0x06, 0x95}};

  std::array<uint8_t, 16> token;
};
}  // namespace PicoIO::SerialComm::Messages
