#ifndef FLOATS_INTERSECTION_H_
#define FLOATS_INTERSECTION_H_

#include "floats/Plane.h"
#include "floats/Ray.h"

namespace fl {

struct IntersectionResult {
  bool didIntersect;
  Vec3 position;
};

inline IntersectionResult intersection(const Plane& plane, const Ray& ray) {
  auto w = (plane.normal * plane.distance) - ray.origin;

  F32 k = dotProduct(w, plane.normal) / dotProduct(ray.direction, plane.normal);

  auto intersection = ray.origin + ray.direction * k;

  return {k >= 0.0f && k <= 1.0f, intersection};
}

}  // namespace fl

#endif  // FLOATS_INTERSECTION_H_
