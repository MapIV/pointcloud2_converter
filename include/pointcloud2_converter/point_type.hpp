#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

struct PointXYZIRS {
  PCL_ADD_POINT4D;
  PCL_ADD_INTENSITY;
  std::uint16_t ring;
  double timestamp;
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;

POINT_CLOUD_REGISTER_POINT_STRUCT(
    PointXYZIRS,
    (float, x, x)(float, y, y)(float, z, z)(float, intensity, intensity)(
        std::uint16_t, ring, ring)(double, timestamp, timestamp))
