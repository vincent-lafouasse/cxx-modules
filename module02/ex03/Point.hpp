#pragma once

#include "Fixed.hpp"

class Point {
public:
   Point();
   Point(const Point& other);
   Point(Fixed, Fixed);
   Point& operator=(const Point& other);
   ~Point();

private:
   Fixed x;
   Fixed y;
};
