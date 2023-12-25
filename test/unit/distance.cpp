/**
 *@file geometry/unit/distance.cpp
 *@author DaHyun Noh (dk3146@naver.com)
 *@brief Point class developments with 2-dimension
 *@version 1.0.0
 *@date 2023-12-20
 *@copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : DaHyun Noh

#include "geometry/distance.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 10000U;
}

namespace nodazi::geometry {

TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}
TEST(GeometryPoint2D, AssignmentOperator) {
  Distance Distance1;
  auto Distance2 = Distance1;
  auto Distance3 = std::move(Distance());
}
}  // namespace nodazi::geometry