#ifndef FLOATS_PLANE_H_
#define FLOATS_PLANE_H_

#include "floats/Vec3.h"

namespace fl {

struct Plane {
  ca::Vec3 normal;
  F32 distance;
};

}  // namespace fl

#endif  // FLOATS_PLANE_H_
