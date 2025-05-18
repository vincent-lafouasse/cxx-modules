#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(Fixed _x, Fixed _y) : x(_x), y(_y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

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

Point::Orientation Point::orientation(Point start, Point end) const {
    Vector ref = end - start;
    Vector v = *this - start;

    // z coordinate of v x ref
    Fixed raw_orientation = v.x * ref.y - v.y * ref.x;

    if (raw_orientation > Fixed(0)) {
        return Left;
    } else if (raw_orientation < Fixed(0)) {
        return Right;
    }
    return Aligned;
}

Point Point::operator+(Point other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(Point other) const {
    return Point(x - other.x, y - other.y);
}
