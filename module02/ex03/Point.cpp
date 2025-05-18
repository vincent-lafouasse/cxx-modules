#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(Fixed _x, Fixed _y): x(_x), y(_y) {}

Point::Point(const Point& other): x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Point::~Point() {}

Fixed Point::dot(Point other) const {
    return Point::dot(*this, other);
}

Fixed Point::dot(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}
