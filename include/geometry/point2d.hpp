/**
 *@file geometry/point2d.hpp
 *@author DaHyun Noh (dk3146@naver.com)
 *@brief Point class declaration with 2-dimension
 *@version 1.0.0
 *@date 2023-12-20
 *@copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : DaHyun Noh

#ifndef NODAZI__GEOMETRY__POINT2D_HPP_
#define NODAZI__GEOMETRY__POINT2D_HPP_

namespace nodazi::geometry {
/**
 * @brief Point class with 2-dimension
 */
class Point2D {
 public:
  /**
   * @brief Construct a new Point2D object
   */
  Point2D() = default;
  /**
   * @brief Construct a new Point2D object with x , y value
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double input_x, double input_y);

  /**
   * @brief Copy Construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(const Point2D& other) = default;
  /**
   * @brief Move Construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(Point2D&& other) noexcept = default;

  /**
   * @brief Destroy the Point2D object
   */
  virtual ~Point2D() = default;

  /**
   * @brief  Copy assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  // Point2D new_one = old_one;
  // new_one.GetX();
  // new_one.GetY();
  auto operator=(const Point2D& other) -> Point2D& = default;

  /**
   * @brief Move assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(Point2D&& other) -> Point2D& = default;

  /**
   * @brief Calculate distance between this point and target point
   * @param target Other Point2D object to calculate distance
   * @return double Euclidean distance between this point and target point
   */
  [[nodiscard]] auto CalculateDistance(const Point2D& target) const -> double;

  [[nodiscard]] static auto CalculateDistance(const Point2D& lhs,
                                              const Point2D& rhs) -> double;
  /**
   * @brief Set x coordinate value
   * @param x Double type input x coordinate value
   */
  void SetX(double input_x);
  /**
   * @brief Set y coordinate value
   * @param y Double type input y coordinate value
   */
  void SetY(double input_y);
  /**
   * @brief Get x coordinate value of this point
   * @return double x coordinate value of this point
   */
  [[nodiscard]] auto GetX() const -> double;
  /**
   * @brief Get y coordinate value of this point
   * @return double y coordinate value of this point
   */
  [[nodiscard]] auto GetY() const -> double;

  /**
   * @brief
   * @param other
   * @return Point2D class = this + other
   */
  auto operator+(const Point2D& other) const -> Point2D;

  /**
   * @brief
   * @param other
   * @return Point2D class = this - other
   */
  auto operator-(const Point2D& other) const -> Point2D;

  /**
   * @brief
   * @param other
   * @return _x += other._x & _y += other._y
   */
  auto operator+=(const Point2D& other) -> void;

  /**
   * @brief
   * @param other
   * @return _x -= other._x & _y -= other._y
   */
  auto operator-=(const Point2D& other) -> void;
  /**
   * @brief
   * @param other
   * @return Point2D class = this * scalar
   */
  auto operator*(double scalar) const -> Point2D;
  /**
   * @brief
   * @param other
   * @return Point2D class = this / scalar
   */
  auto operator/(double scalar) const -> Point2D;

  /**
   * @brief
   *
   * @param other
   * @return true if this == other
   * @return false if this != other
   */
  auto operator==(const Point2D& other) const -> bool;
  /**
   * @brief
   *
   * @param other
   * @return true if this == other
   * @return false if this != other
   */
  auto operator!=(const Point2D& other) const -> bool;

 protected:
 private:
  double x_{0.0};
  double y_{0.0};
};
}  // namespace nodazi::geometry
#endif