
#include <cassert>
#include <cstdlib>

#include "Point.hpp"

namespace {
void test_orientation();
}  // namespace

int main() {
    test_orientation();
}

namespace {
void test_orientation() {
    Point o(Fixed(0), Fixed(0));
    Point i(Fixed(0), Fixed(0));
    Point j(Fixed(0), Fixed(0));

    assert(j.orientation(o, i) == Point::Orientation::Left);
}
}  // namespace
