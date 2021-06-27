#pragma once

#include <nucleus/Types.h>

#undef near
#undef far

namespace fl {

struct Frustum {
  F32 left;
  F32 right;
  F32 bottom;
  F32 top;
  F32 near;
  F32 far;
};

}  // namespace fl
