#pragma once

#include "floats/vec3.h"

namespace fl {

struct Plane {
  Vec3 normal;
  F32 distance;
};

}  // namespace fl
