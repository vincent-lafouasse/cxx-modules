#pragma once

#include "Fixed.hpp"

class Point {
public:
   Point();
   Point(const Point& other);
   Point(Fixed, Fixed);
   Point& operator=(const Point& other);
   ~Point();

   Fixed dot(Point other) const;
   static Fixed dot(Point p1, Point p2);

private:
   Fixed x;
   Fixed y;
};
