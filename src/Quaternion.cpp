#include "floats//Quaternion.h"

namespace fl {

// static
const Quaternion Quaternion::identity{1.0f, Vec3::zero};

Quaternion fromAxisAngle(const Vec3& axis, const Angle& angle) {
  F32 thetaOverTwo = angle.radians() / 2.0f;
  F32 sineThetaOverTwo = sine(thetaOverTwo);
  return {cosine(thetaOverTwo), axis * sineThetaOverTwo};
}

Quaternion fromRotationMatrix(const Mat3& NU_UNUSED(rotationMatrix)) {
  return Quaternion::identity;
}

Quaternion inverse(const Quaternion& q) {
  return {q.w, -q.v};
}

Quaternion slerp(const Quaternion& a, const Quaternion& b, F32 t) {
  return ((b * inverse(a)) ^ t) * a;
}

}  // namespace fl
