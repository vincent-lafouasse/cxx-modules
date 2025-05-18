
#include <cassert>

#include "Point.hpp"

extern bool bsp(Point const a, Point const b, Point const c, Point const point);

namespace {
void test_orientation();
void test_bsp();
}  // namespace

int main() {
    test_orientation();
    test_bsp();
}

namespace {
void test_orientation() {
    Point o(Fixed(0), Fixed(0));
    Point i(Fixed(1), Fixed(0));
    Point j(Fixed(0), Fixed(1));

    assert(j.orientation(o, i) == Point::Orientation::Left);
    assert(i.orientation(o, j) == Point::Orientation::Right);
    assert(j.orientation(o, j) == Point::Orientation::Aligned);
    assert(o.orientation(i, j) == Point::Orientation::Left);
}

void test_bsp() {
    Point o(Fixed(0), Fixed(0));
    Point i(Fixed(69.3f), Fixed(0));
    Point j(Fixed(0), Fixed(420.f));

    Point a(Fixed(-1), Fixed(-1));
    Point b(Fixed(1), Fixed(1));
    Point c(Fixed(42.f), Fixed(69.f));

    assert(bsp(o, i, j, o));
    assert(bsp(o, i, j, i));
    assert(bsp(o, i, j, j));

    assert(!bsp(o, i, j, a));
    assert(bsp(o, i, j, b));
    assert(bsp(o, i, j, c));
}
}  // namespace
