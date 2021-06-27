#pragma once

#include "floats/vec3.h"
#include "nucleus/macros.h"

namespace fl {

struct Mat3 {
  static Mat3 identity;

  Vec3 col[3];

  // Construct from axes.
  Mat3(const Vec3& right, const Vec3& up, const Vec3& forward) : col{right, up, forward} {}
};

inline Mat3 operator-(const Mat3& m) {
  return {
      -m.col[0],
      -m.col[1],
      -m.col[2],
  };
}

inline Vec3 operator*(const Mat3& left, const Vec3& right) {
  return {
      left.col[0].x * right.x + left.col[1].x * right.y + left.col[2].x * right.z,
      left.col[0].y * right.x + left.col[1].y * right.y + left.col[2].y * right.z,
      left.col[0].z * right.x + left.col[1].z * right.y + left.col[2].z * right.z,
  };
}

inline Mat3 fromRotationAxis(const Vec3& NU_UNUSED(axis), F32 NU_UNUSED(rotationInDegrees)) {
  return Mat3::identity;
}

Mat3 transpose(const Mat3& m);

}  // namespace fl
