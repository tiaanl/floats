#pragma once

#include "floats/angle.h"
#include "floats/frustum.h"
#include "floats/mat4.h"
#include "floats/quaternion.h"
#include "floats/rect.h"

namespace fl {

Mat4 scale_matrix(F32 scale);
Mat4 scale_matrix(const Vec3& scale);

Mat4 translation_matrix(const Vec3& translate);
Mat4 rotation_matrix(const Vec3& axis, Angle angle);

Mat4 frustum_matrix(F32 left, F32 right, F32 bottom, F32 top, F32 near, F32 far);
Mat4 frustum_matrix(const Frustum& frustum);

Mat4 orthographic_projection(F32 left, F32 right, F32 top, F32 bottom, F32 near, F32 far);
Mat4 perspective_projection(Angle field_of_view, F32 aspect_ratio, F32 near, F32 far);

Mat4 look_at(const Vec3& eye, const Vec3& target, const Vec3& world_up);

Mat4 create_view_matrix(const Vec3& position, const Quaternion& orientation);

Mat4 create_model_matrix(const Mat4& translation, const Mat4& rotation, const Mat4& scale);

}  // namespace fl
