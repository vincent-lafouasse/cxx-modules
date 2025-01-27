#include "Fixed.hpp"

#include <vector>
#include <array>
#include <cassert>

static void given_test() {
    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
}

static void test_integer_addition() {
    const std::vector<std::array<int, 2>> pairs = {
        {0, 0},
        {1, 2},
        {4, 5},
        {18, 19},
    };

    for (size_t i = 0; i < pairs.size(); i++) {
        int __a = pairs[i][0];
        int __b = pairs[i][1];

        Fixed a(__a);
        Fixed b(__b);
        Fixed s = a + b;

        assert(s.toInt() == __a + __b);
    }
}

int main() {
    test_integer_addition();
}
