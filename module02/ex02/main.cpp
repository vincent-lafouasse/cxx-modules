#include "Fixed.hpp"

#include <cassert>
#include <cstdint>

static void given_test();
static void test_integer_addition();

int main() {
    given_test();
    // test_integer_addition();
}

static void given_test() {
    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    // std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "Expected outout\n";
    std::cout << "0.00390625\n";
    std::cout << "0.00390625\n";
    std::cout << "0.00390625\n";
    std::cout << "0.0078125\n";
    std::cout << "10.1016\n";
    std::cout << "10.1016\n";
}

struct Vec2 {
    int a;
    int b;
};

static void test_integer_addition() {
    const Vec2 pairs[] = {
        {1, 2}, {2, 3}, {INT32_MAX, INT32_MIN}, {INT32_MAX, INT32_MAX}};
    size_t sz = sizeof(pairs) / sizeof(*pairs);

    for (size_t i = 0; i < sz; i++) {
        int __a = pairs[i].a;
        int __b = pairs[i].b;

        Fixed a(__a);
        Fixed b(__b);
        Fixed s = a + b;

        assert(s.toInt() == __a + __b);
    }
    std::cout << "test integer addition ok\n";
}
