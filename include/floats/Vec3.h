#ifndef FLOATS_VEC3_H_
#define FLOATS_VEC3_H_

#include <ostream>

#include "floats/Common.h"
#include "floats/Vec2.h"
#include "nucleus/Types.h"

namespace fl {

struct Vec3 {
  static Vec3 zero;

  // OpenGL normalized device coordinates.
  static Vec3 right;
  static Vec3 up;
  static Vec3 forward;

  F32 x;
  F32 y;
  F32 z;

  Vec3(F32 x, F32 y, F32 z) : x{x}, y{y}, z{z} {}
  Vec3(const Vec2& xy, F32 z) : x{xy.x}, y{xy.y}, z{z} {}

  Vec2 xy() const {
    return {x, y};
  }

  Vec3 operator-() const {
    return Vec3{-x, -y, -z};
  }

  Vec3& operator+=(const Vec3& right) {
    x += right.x;
    y += right.y;
    z += right.z;

    return *this;
  }

  Vec3& operator-=(const Vec3& right) {
    x -= right.x;
    y -= right.y;
    z -= right.z;

    return *this;
  }

  Vec3& operator*=(F32 right) {
    x *= right;
    y *= right;
    z *= right;

    return *this;
  }

  Vec3& operator/=(F32 right) {
    x /= right;
    y /= right;
    z /= right;

    return *this;
  }
};

inline Vec3 operator+(const Vec3& left, const Vec3& right) {
  return Vec3{left.x + right.x, left.y + right.y, left.z + right.z};
}

inline Vec3 operator-(const Vec3& left, const Vec3& right) {
  return Vec3{left.x - right.x, left.y - right.y, left.z - right.z};
}

inline Vec3 operator*(const Vec3& left, F32 right) {
  return Vec3{left.x * right, left.y * right, left.z * right};
}

inline Vec3 operator/(const Vec3& left, F32 right) {
  return Vec3{left.x / right, left.y / right, left.z / right};
}

inline F32 dotProduct(const Vec3& left, const Vec3& right) {
  return left.x * right.x + left.y * right.y + left.z * right.z;
}

inline Vec3 crossProduct(const Vec3& left, const Vec3& right) {
  return Vec3{left.y * right.z - left.z * right.y, left.z * right.x - left.x * right.z,
              left.x * right.y - left.y * right.x};
}

inline F32 lengthSquared(const Vec3& vec) {
  return dotProduct(vec, vec);
}

inline F32 length(const Vec3& vec) {
  return squareRoot(lengthSquared(vec));
}

inline Vec3 normalize(const Vec3& vec) {
  return vec * (1.0f / length(vec));
}

inline Vec3 lerp(const Vec3& a, const Vec3& b, F32 t) {
  return a + (b - a) * t;
}

inline std::ostream& operator<<(std::ostream& os, const Vec3& value) {
  os << "{" << value.x << ", " << value.y << ", " << value.z << "}";
  return os;
}

}  // namespace fl

#endif  // FLOATS_VEC3_H_
