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

TEST(GeometryDistance, ConstructorWithInputValue) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    Distance distance1(static_cast<double>(std::rand()));
    Distance distance2(static_cast<double>(std::rand()),
                       Distance::Type::kKilometer);
    Distance distance3(static_cast<double>(std::rand()),
                       Distance::Type::kMeter);
    Distance distance4(static_cast<double>(std::rand()),
                       Distance::Type::kCentimeter);
    Distance distance5(static_cast<double>(std::rand()),
                       Distance::Type::kMillimeter);
    Distance distance6(static_cast<double>(std::rand()),
                       Distance::Type::kMicrometer);
    Distance distance7(static_cast<double>(std::rand()),
                       Distance::Type::kNanometer);
  }
}

TEST(GeometryPoint2D, AssignmentOperator) {
  Distance Distance1;
  auto Distance2 = Distance1;
  auto Distance3 = std::move(Distance());
}

TEST(GeometryDistance, GetValue) {
  const auto kInputValue = static_cast<double>(2038.0);

  Distance distance1(kInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2(kInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(kInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3(kInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4(kInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5(kInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6(kInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance6.GetValue(Distance::Type::kNanometer));
}

TEST(GeometryDistance, SetValue) {
  const auto kInputValue = static_cast<double>(2038.0);

  Distance distance1;
  distance1.SetValue(kInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2;
  distance2.SetValue(kInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(kInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3;
  distance3.SetValue(kInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4;
  distance4.SetValue(kInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5;
  distance5.SetValue(kInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(kInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6;
  distance6.SetValue(kInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(kInputValue, distance6.GetValue(Distance::Type::kNanometer));
}

TEST(GeometryDistance, OperatorEqual) {
  const auto kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo == distance);
  EXPECT_TRUE(distance_by_kilo == distance_by_nano);
  EXPECT_TRUE(distance_by_nano == distance);
}

TEST(GeometryDistance, OperatorNotEqual) {
  const auto kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_FALSE(distance_by_kilo != distance);
  EXPECT_FALSE(distance_by_kilo != distance_by_nano);
  EXPECT_FALSE(distance_by_nano != distance);
}

TEST(GeometryDistance, OperatorBigger) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto distance1_value = std::rand();
    const auto distance2_value = std::rand();

    Distance distance1(distance1_value);
    Distance distance2(distance2_value);

    EXPECT_EQ((distance1_value < distance2_value), (distance1 < distance2));
  }
}

TEST(GeometryDistance, OperatorBiggerEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto distance1_value = std::rand();
    const auto distance2_value = std::rand();

    Distance distance1(distance1_value);
    Distance distance2(distance2_value);

    EXPECT_EQ((distance1_value <= distance2_value), (distance1 <= distance2));
  }
}

TEST(GeometryDistance, OperatorPlus) {
  const auto kInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(kInputValue, Distance::Type::kKilometer);
  Distance distance(kInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(kInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo + distance;
  const auto distance2 = distance_by_kilo + distance_by_nano;
  const auto distance3 = distance + distance_by_nano;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   kInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   kInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   kInputValue * 2.0);
}

}  // namespace nodazi::geometry