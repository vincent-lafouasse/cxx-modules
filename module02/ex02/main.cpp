#include "Fixed.hpp"

#include <cassert>
#include <cstdlib>
#include <ctime>

namespace {
void given_test();
void test(float a, float b);

float random_float(float low, float hi);
float random_float();

}  // namespace

int main() {
    std::srand(static_cast<unsigned>(time(0)));

    given_test();

    test(5.0, 2.0);
    test(1000.0, 3.0);
    test(3.0, 1000.0);
    test(random_float(), random_float());
}

namespace {
void given_test() {
    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "Expected outout\n";
    std::cout << "0.00390625\n";
    std::cout << "0.00390625\n";
    std::cout << "0.00390625\n";
    std::cout << "0.0078125\n";
    std::cout << "10.1016\n";
    std::cout << "10.1016\n";
}

void test(float __a, float __b) {
    std::cout << "With input " << __a << " " << __b << "\n";

    Fixed a(__a);
    Fixed b(__b);
    std::cout << "a\t= " << a << '\n';
    std::cout << "b\t= " << b << '\n';
    std::cout << "a + b\t= " << a + b << '\n';
    std::cout << "a - b\t= " << a - b << '\n';
    std::cout << "a * b\t= " << a * b << '\n';
    std::cout << "a / b\t= " << a / b << '\n';
}

float random_float(float low, float hi) {
    float range = hi - low;
    return low +
           range * static_cast<float>(rand()) / (static_cast<float>(RAND_MAX));
}

float random_float() {
    return random_float(-4096.f, 4096.f);
}
}  // namespace
