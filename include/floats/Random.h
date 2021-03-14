#pragma once

#include <cstdlib>
#include <ctime>

namespace fl {

auto randomInt() -> I32 {
  std::time_t t;
  std::time(&t);
  std::srand(t);
  return std::rand();
}

}  // namespace fl
