#pragma once

#include "floats/angle.h"
#include "floats/frustum.h"
#include "floats/mat4.h"
#include "floats/quaternion.h"
#include "floats/rect.h"

namespace fl {

Mat4 scaleMatrix(F32 scale);
Mat4 scaleMatrix(const Vec3& scale);

Mat4 translationMatrix(const Vec3& translate);
Mat4 rotationMatrix(const Vec3& axis, Angle angle);

Mat4 frustumMatrix(F32 left, F32 right, F32 bottom, F32 top, F32 near, F32 far);
Mat4 frustumMatrix(const Frustum& frustum);

Mat4 orthographicProjection(F32 left, F32 right, F32 top, F32 bottom, F32 near, F32 far);
Mat4 perspectiveProjection(Angle fieldOfView, F32 aspectRatio, F32 near, F32 far);

Mat4 lookAt(const Vec3& eye, const Vec3& target, const Vec3& worldUp);

Mat4 createViewMatrix(const Vec3& position, const Quaternion& orientation);

Mat4 createModelMatrix(const Mat4& translation, const Mat4& rotation, const Mat4& scale);

}  // namespace fl
