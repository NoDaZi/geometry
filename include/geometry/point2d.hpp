/**
 *@file geometry/point2d.hpp
 *
 *
 *
 *
 *
 */

// Copyright (c)
// Authors :

#ifndef NODAZI_GEOMETRY__POINT__2D__HPP_
#define NODAZI_GEOMETRY__POINT__2D__HPP_

namespace nodazi::geometry {

class Point2D {
 public:
  /*
   * @brief Construct a new Point2D object
   */
  Point2D() = default;
  /*
   * @brief Construct a new Point2D object with x , y value
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double x, double y);

  Point2D(const Point2D& other) = default;

  Point2D(Point2D&& other)->Point2D = default;

  virtual ~Point2D() = default;

  auto CalculateDistance(const Point2D& target) const -> double {
    void SetX(double x) void SetY(double y)

        auto GetX() const -> double;
    auto GetY() const -> double;

   protected:
   private:
    /**
     *brief Point class with 2-dimension
     */
  }
}

#endif