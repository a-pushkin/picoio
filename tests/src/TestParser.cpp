#include <gtest/gtest.h>

#include "msg/Parser.hpp"
#include "msg/msg/Sync.hpp"

namespace {

using namespace PicoIO::SerialComm;

TEST(Parser, MessageLength) {
  EXPECT_TRUE(Parser::is_fixed_length(Messages::Sync::id));

  EXPECT_EQ(Parser::get_fixed_length(Messages::Sync::id), 16);
}

}  // namespace
