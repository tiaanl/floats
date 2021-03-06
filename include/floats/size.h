#pragma once

#include <ostream>

#include "floats/common.h"

namespace fl {

struct Size {
  I32 width = 0;
  I32 height = 0;

  Size() = default;

  Size(I32 width, I32 height) : width(width), height(height) {}

  bool operator==(const Size& right) const {
    return width == right.width && height == right.height;
  }

  bool operator!=(const Size& right) const {
    return !(*this == right);
  }

  I32 area() const {
    return width * height;
  }
};

inline std::ostream& operator<<(std::ostream& os, const Size& value) {
  os << "{" << value.width << ", " << value.height << "}";
  return os;
}

inline F32 aspect_ratio(const Size& size) {
  if (size.height == 0) {
    return 1.0f;
  }

  return static_cast<F32>(size.width) / static_cast<F32>(size.height);
}

template <>
inline auto minimum<Size>(const Size& x, const Size& y) -> Size {
  return Size{minimum(x.width, y.width), minimum(x.height, y.height)};
}

template <>
inline auto maximum<Size>(const Size& x, const Size& y) -> Size {
  return Size{maximum(x.width, y.width), maximum(x.height, y.height)};
}

}  // namespace fl
