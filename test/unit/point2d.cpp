// Copyright (c) 2023 Nodazi, All Rights Reserves
// Author : DaHyun Noh

#include "geometry/point2d.hpp"

#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"

namespace nodazi::geometry {
TEST(GeometryPoint2D, Constructor) {
  Point2D point1;
  Point2D point2(0.0, 1.0);
  Point2D point3(point2);
  Point2D point4(std::move(Point2D()));
}

TEST(GeometryPoint2D, AssignmentOperator) {
  Point2D point1;
  auto point2 = point1;
  auto point3 = std::move(Point2D());
}
}  // namespace nodazi::geometry
