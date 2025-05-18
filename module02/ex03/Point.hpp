#pragma once

#include "Fixed.hpp"

class Point {
   public:
    typedef Point Vector;

    Point();
    Point(const Point& other);
    Point(Fixed, Fixed);
    Point& operator=(const Point& other);
    ~Point();

    Point operator+(Point other) const;
    Point operator-(Point other) const;

    Fixed dot(Point other) const;
    static Fixed dot(Point p1, Point p2);

    enum Orientation { Aligned, Left, Right };

    Orientation orientation(Point start, Point end) const;

   private:
    Fixed x;
    Fixed y;
};
