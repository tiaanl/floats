#include "floats/transform.h"

namespace fl {

Mat4 scale_matrix(F32 scale) {
  return scale_matrix(Vec3{scale, scale, scale});
}

Mat4 scale_matrix(const Vec3& scale) {
  return Mat4{
      Vec4{scale.x, 0.0f, 0.0f, 0.0f},
      Vec4{0.0f, scale.y, 0.0f, 0.0f},
      Vec4{0.0f, 0.0f, scale.z, 0.0f},
      Vec4{0.0f, 0.0f, 0.0f, 1.0f},
  };
}

Mat4 translation_matrix(const Vec3& translate) {
  Mat4 result = Mat4::identity;
  result.col[3] = Vec4{translate, 1.0f};
  return result;
}

Mat4 rotation_matrix(const Vec3& axis, Angle angle) {
  const auto normalized_axis = normalize(axis);

  const F32 sin_theta = sine(angle);
  const F32 cos_theta = cosine(angle);
  const F32 cos_value = 1.0f - cos_theta;

  return {
      {
          (normalized_axis.x * normalized_axis.x * cos_value) + cos_theta,
          (normalized_axis.x * normalized_axis.y * cos_value) + (normalized_axis.z * sin_theta),
          (normalized_axis.x * normalized_axis.z * cos_value) - (normalized_axis.y * sin_theta),
          0.0f,
      },
      {
          (normalized_axis.y * normalized_axis.x * cos_value) - (normalized_axis.z * sin_theta),
          (normalized_axis.y * normalized_axis.y * cos_value) + cos_theta,
          (normalized_axis.y * normalized_axis.z * cos_value) + (normalized_axis.x * sin_theta),
          0.0f,
      },
      {
          (normalized_axis.z * normalized_axis.x * cos_value) + (normalized_axis.y * sin_theta),
          (normalized_axis.z * normalized_axis.y * cos_value) - (normalized_axis.x * sin_theta),
          (normalized_axis.z * normalized_axis.z * cos_value) + cos_theta,
          0.0f,
      },
      {
          0.0f,
          0.0f,
          0.0f,
          1.0f,
      },
  };
}

Mat4 frustum_matrix(F32 left, F32 right, F32 bottom, F32 top, F32 near, F32 far) {
  F32 dx = right - left;
  F32 dy = top - bottom;
  F32 dz = far - near;

  return {{
              (2.0f * near) / dx,
              0.0f,
              0.0f,
              0.0f,
          },
          {
              0.0f,
              (2.0f * near) / dy,
              0.0f,
              0.0f,
          },
          {
              (right + left) / dx,
              (top + bottom) / dy,
              -(far + near) / dz,
              -1.0f,
          },
          {
              0.0f,
              0.0f,
              -(2.0f * near * far) / dz,
              0.0f,
          }};
}

Mat4 frustum_matrix(const Frustum& frustum) {
  return frustum_matrix(frustum.left, frustum.right, frustum.bottom, frustum.top, frustum.near,
                        frustum.far);
}

Mat4 orthographic_projection(F32 left, F32 right, F32 top, F32 bottom, F32 near, F32 far) {
  auto col1 = Vec4{2.0f / (right - left), 0.0f, 0.0f, 0.0f};

  auto col2 = Vec4{0.0f, 2.0f / (top - bottom), 0.0f, 0.0f};

  auto col3 = Vec4{0.0f, 0.0f, -2.0f / (far - near), 0.0f};

  auto col4 = Vec4{-(right + left) / (right - left), -(top + bottom) / (top - bottom),
                   -(far + near) / (far - near), 1.0f};

  return Mat4{col1, col2, col3, col4};
}

Mat4 perspective_projection(Angle field_of_view, F32 aspect_ratio, F32 near, F32 far) {
  F32 t = tangent(field_of_view / 2.0f);

  F32 height = near * t;
  F32 width = height * aspect_ratio;

  return frustum_matrix(-width, width, -height, height, near, far);
}

Mat4 look_at(const Vec3& eye, const Vec3& target, const Vec3& world_up) {
  auto f = normalize(target - eye);
  auto s = normalize(crossProduct(f, world_up));
  auto u = crossProduct(s, f);

  auto result = Mat4::identity;

  result.col[0].x = s.x;
  result.col[1].x = s.y;
  result.col[2].x = s.z;

  result.col[0].y = u.x;
  result.col[1].y = u.y;
  result.col[2].y = u.z;

  result.col[0].z = -f.x;
  result.col[1].z = -f.y;
  result.col[2].z = -f.z;

  result.col[3].x = -dotProduct(s, eye);
  result.col[3].y = -dotProduct(u, eye);
  result.col[3].z = dotProduct(f, eye);

  return result;
}

Mat4 create_view_matrix(const Vec3& position, const Quaternion& orientation) {
  Mat3 rotation = orientation.toRotationMatrix();

  Mat3 transposed_rotation = transpose(rotation);
  Vec3 translation = -transposed_rotation * position;

  Mat4 view_matrix = Mat4{transposed_rotation};
  view_matrix.col[3] = {translation, 1.0f};

  return view_matrix;
}

Mat4 create_model_matrix(const Mat4& translation, const Mat4& rotation, const Mat4& scale) {
  return translation * rotation * scale;
}

}  // namespace fl
