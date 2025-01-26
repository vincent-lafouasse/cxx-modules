#include "Fixed.hpp"

#include <vector>
#include <array>

int main() {
    /*
    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
    */

    std::vector<std::array<int, 3>> pairs = {
        {0, 0, 1},
        {1, 2, 2},
        {4, 5, 4},
        {18, 19, 10},
    };

    for (size_t i = 0; i < pairs.size(); i++) {
        Fixed a;
        a.setRawBits(pairs[i][0]);
        Fixed b;
        a.setRawBits(pairs[i][1]);

        Fixed s = a + b;
    }
}
