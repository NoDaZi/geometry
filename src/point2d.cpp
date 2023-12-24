/**
 *@file geometry/point2d.cpp
 *@author DaHyun Noh (dk3146@naver.com)
 *@brief Point class developments with 2-dimension
 *@version 1.0.0
 *@date 2023-12-20
 *@copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : DaHyun Noh

#include "geometry/point2d.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"

namespace nodazi::geometry {
Point2D::Point2D(double input_x, double input_y) : x_(input_x), y_(input_y){};

auto Point2D::CalculateDistance(const Point2D& target) const -> double {
  return std::sqrt(std::pow((x_ - target.x_), 2) + std::pow(y_ - target.y_, 2));
}

}  // namespace nodazi::geometry
