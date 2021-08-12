#pragma once

#include <cstdlib>
#include <ctime>

namespace fl {

auto randomInt() -> I32 {
  return std::rand();
}

}  // namespace fl
