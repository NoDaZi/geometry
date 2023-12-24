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

TEST(GeometryPoint2D, CalculateDistance) {
  constexpr uint32_t kTestCount = 10000U;
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(std ::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                               (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    source.CalculateDistance(target));
  }
}

TEST(GeometryPoint2D, StaticCalculateDistance) {
  constexpr uint32_t kTestCount = 10000U;
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(std ::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                               (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    Point2D::CalculateDistance(source, target));
  }
}

TEST(GeometryPoint2D, GetX) {
  constexpr uint32_t kTestCount = 10000U;
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source(kSourceX, 0);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, GetY) {
  constexpr uint32_t kTestCount = 10000U;
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source(0, kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, SetX) {
  constexpr uint32_t kTestCount = 10000U;
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source;

    source.SetX(kSourceX);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, SetY) {
  constexpr uint32_t kTestCount = 10000U;
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source;

    source.SetY(kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}

}  // namespace nodazi::geometry
