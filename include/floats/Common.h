#ifndef FLOATS_COMMON_H_
#define FLOATS_COMMON_H_

#include <algorithm>
#include <cmath>

#include "floats/Angle.h"
#include "floats/Size.h"
#include "nucleus/Logging.h"
#include "nucleus/Types.h"

namespace fl {

constexpr F32 kNearZero = 0.00001f;  // 1.0f / static_cast<F32>(1U << 16U);

inline F32 sine(F32 radians) {
  return std::sin(radians);
}

inline F32 sine(Angle angle) {
  return sine(angle.radians());
}

inline F32 arcSine(F32 radians) {
  return std::asin(radians);
}

inline F32 arcSine(Angle angle) {
  return arcSine(angle.radians());
}

inline F32 cosine(F32 radians) {
  return std::cos(radians);
}

inline F32 cosine(Angle angle) {
  return cosine(angle.radians());
}

inline F32 arcCosine(F32 radians) {
  return std::acos(radians);
}

inline F32 arcCosine(Angle angle) {
  return arcCosine(angle.radians());
}

inline F32 tangent(F32 radians) {
  return std::tan(radians);
}

inline F32 tangent(Angle angle) {
  return tangent(angle.radians());
}

inline F32 arcTangent(F32 radians) {
  return std::atan(radians);
}

inline F32 arcTangent(Angle angle) {
  return arcTangent(angle.radians());
}

inline F32 arcTangent2(F32 y, F32 x) {
  return std::atan2(y, x);
}

inline Angle arcTangent2Angle(F32 y, F32 x) {
  return radians(arcTangent2(y, x));
}

inline F32 round(F32 x) {
  return std::roundf(x);
}

inline F32 squareRoot(F32 x) {
  return std::sqrt(x);
}

inline F32 absolute(F32 x) {
  return x < 0.0f ? -x : x;
}

inline bool nearZero(F32 x) {
  return absolute(x) < kNearZero;
}

inline F32 clamp(F32 value, F32 min, F32 max) {
  DCHECK(min < max) << "min value should be less than max value";

  return std::min(max, std::max(value, min));
}

template <typename T>
inline auto minimum(const T& x, const T& y) -> T {
  return x < y ? x : y;
}

template <>
inline auto minimum<Size>(const Size& x, const Size& y) -> Size {
  return Size{minimum(x.width, y.width), minimum(x.height, y.height)};
}

template <typename T>
inline auto maximum(const T& x, const T& y) -> T {
  return x < y ? y : x;
}

template <>
inline auto maximum<Size>(const Size& x, const Size& y) -> Size {
  return Size{maximum(x.width, y.width), maximum(x.height, y.height)};
}

}  // namespace fl

#endif  // FLOATS_COMMON_H_
