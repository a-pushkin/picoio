#include <gtest/gtest.h>

#include "msg/Parser.hpp"
#include "msg/msg/Reset.hpp"

namespace {

using namespace PicoIO::SerialComm;

TEST(Parser, IsFixedLength) {
  EXPECT_TRUE(Parser::is_fixed_length(Messages::Reset::id));
}

}  // namespace
