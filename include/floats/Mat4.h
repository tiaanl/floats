#ifndef FLOATS_MAT4_H_
#define FLOATS_MAT4_H_

#include "floats/Mat3.h"
#include "floats/Vec4.h"

namespace fl {

struct Mat4 {
  static Mat4 identity;

  Vec4 col[4];

  Mat4(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4)
    : col{col1, col2, col3, col4} {}

  // Create a basis matrix. Vectors should all be orthogonal to each other and be normalized.
  Mat4(const Vec3& right, const Vec3& up, const Vec3& forward,
       const Vec3& position = {0.0f, 0.0f, 0.0f})
    : col{{right, 0.0f}, {up, 0.0f}, {forward, 0.0f}, {position, 1.0f}} {}

  Mat4(const Mat3& m)
    : col{{m.col[0], 0.0f}, {m.col[1], 0.0f}, {m.col[2], 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}} {}
};

Mat4 operator*(const Mat4& left, const Mat4& right);
Vec4 operator*(const Mat4& left, const Vec4& right);
Vec4 operator*(const Vec4& left, const Mat4& right);

Mat4 transpose(const Mat4& m);
Mat4 inverse(const Mat4& m);

}  // namespace fl

#endif  // FLOATS_MAT4_H_
