#ifndef FLOATS_RAY_H_
#define FLOATS_RAY_H_

#include "floats/Vec3.h"

namespace fl {

struct Ray {
  Vec3 origin;
  Vec3 direction;
};

}  // namespace fl

#endif  // FLOATS_RAY_H_
