/**
 *@file geometry/distance.hpp
 *@author DaHyun Noh (dk3146@naver.com)
 *@brief Point class declaration with 2-dimension
 *@version 1.0.0
 *@date 2023-12-20
 *@copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : DaHyun Noh

#ifndef NODAZI__GEOMETRY__DISTANCE_HPP_
#define NODAZI__GEOMETRY__DISTANCE_HPP_

#include <cstdint>

namespace nodazi::geometry {
/**
 * @brief The class for abstract distance
 */
class Distance {
 public:
  /**
   * @brief The enum class for distance type.
   */
  enum class Type {
    kKilometer = 0,
    kMeter = 1,
    kCentimeter = 2,
    kMillimeter = 3,
    kMicrometer = 4,
    kNanometer = 5
  };

  /**
   * @brief Construct a new Distance object
   */
  Distance() = default;

  /**
   * @brief Construct a new Distance object
   * @param input_value
   * @param input_type
   */
  explicit Distance(double input_value, Type input_type = Type ::kMeter);

  /**
   * @brief Construct a new Distance object
   * @param other
   */
  Distance(const Distance& other) = default;

  /**
   * @brief Destroy a new Distance object
   */
  Distance(Distance&& other) noexcept = default;
  /**
   * @brief Destroy the Distance object
   *
   */
  virtual ~Distance() = default;

  /**
   * @brief
   * @param other
   * @return Distance&
   */
  auto operator=(const Distance& other) -> Distance& = default;

  /**
   * @brief
   * @param other
   * @return Distance&
   */
  auto operator=(Distance&& other) -> Distance& = default;

  /**
   * @brief Get the Distance Value for distance type.
   * @param input_type The distance type.
   * @return double The distance value.
   */
  [[nodiscard]] auto GetValue(const Type& input_type) const -> double;
  /**
   * @brief Set the Distance value for distance type.
   * @param input_value  The distance value.
   * @param input_type  The distance type.
   */
  auto SetValue(double input_value, const Type& input_type) -> void;
  /**
   * @brief Compare with other distance object for equality.
   * @param other Distance
   * @return true If Distance is Equal
   * @return false If Distance is not Equal
   */
  auto operator==(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for not equality.
   * @param other Distance
   * @return true If Distance is not Equal
   * @return false If Distance is Equal
   */
  auto operator!=(const Distance& other) const -> bool;

  auto operator<(const Distance& other) const -> bool;
  auto operator<=(const Distance& other) const -> bool;

  auto operator>(const Distance& other) const -> bool;
  auto operator>=(const Distance& other) const -> bool;

  /**
   * @brief Add other distance object.
   * @param other The other distance object.
   * @return Distance The result of addition.
   */
  auto operator+(const Distance& other) const -> Distance;
  auto operator-(const Distance& other) const -> Distance;

  auto operator*(double scale) const -> Distance;
  auto operator/(double scale) const -> Distance;

  auto operator+=(const Distance& other) const -> void;
  auto operator-=(const Distance& other) const -> void;

  auto operator*=(double scale) const -> void;
  auto operator/=(double scale) const -> void;

 protected:
 private:
  int64_t nanometer_{0};

}
// 거리에 대한 정보를 저장하고 연산하는 클래스
// 추상화를 통해 구현을 숨기고, 사용자에게 필요한 기능만 제공한다.
// 사용자는 구현에 대해 알 필요가 없다.

// 특징
// 거리 type은 kilometer, meter, centimeter, millimeter, micrometer, nanometer
// 정확도는 1nm까지 허용한다.
// 1kilometer = 1,000meter
// 1meter = 100centimeter
// 1centimeter = 10millimeter
// 1millimeter = 1,000micrometer
// 1micrometer = 1,000nanometer
// 1kilometer = 1.0 * 10^3 meter = 1.0 * 10^6 centimeter = 1.0 * 10^7 millimeter
// = 1.0 * 10^9 micrometer = 1.0 * 10^12 nanometer

// 일반적으론 floating point type을 사용한다.
// distance 값은 int64_t로 관리한다.
// int64_t 최소값은 -9,223,372,036,854,775,808
// int64_t 최대값은 9,223,372,036,854,775,807
// 9,223,372,036,854,775,808 나노미터는 킬로미터로는 9,223,372.037km이다.

// double type은 연산을 하게 되면 불확실성이 생김
// floating point가 사칙연사에대해서 비용이 int type보다 훨씬 크다.
;
}  // namespace nodazi::geometry

#endif
