#include "Fixed.hpp"

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>

[[maybe_unused]] static void given_test();
static void test_integer_addition_difference();
static void test_integer_addition_difference_stochastic(int N);
static void test_int_mult_div_stochastic(int N);

static int32_t random_int(int32_t low, int32_t hi);
static float random_float(float low, float hi);
static bool float_eq(float a, float b, float e);

int main() {
    std::srand(static_cast<unsigned>(time(0)));

    // given_test();
    test_integer_addition_difference();
    test_integer_addition_difference_stochastic(1000000);
    test_int_mult_div_stochastic(5);
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

static void test_integer_addition_difference() {
    const Vec2 pairs[] = {
        {1, 2}, {2, 3}, {INT32_MAX, INT32_MIN}, {INT32_MAX, INT32_MAX}};
    size_t sz = sizeof(pairs) / sizeof(*pairs);

    for (size_t i = 0; i < sz; i++) {
        int __a = pairs[i].a;
        int __b = pairs[i].b;

        Fixed a(__a);
        Fixed b(__b);
        Fixed sum = a + b;
        Fixed diff = a - b;

        assert(sum.toInt() == __a + __b);
        assert(diff.toInt() == __a - __b);
    }
    std::cout << "test integer +/- ok\n";
}

static void test_integer_addition_difference_stochastic(int N) {
    for (int _ = 0; _ < N; _++) {
        int __a = random_int(-2048, 2048);
        int __b = random_int(-2048, 2048);

        Fixed a(__a);
        Fixed b(__b);
        Fixed sum = a + b;
        Fixed diff = a - b;

        assert(sum.toInt() == __a + __b);
        assert(diff.toInt() == __a - __b);
    }

    std::cout << "stochastic test integer +/- ok\n";
}

static void test_int_mult_div_stochastic(int N) {
    for (int _ = 0; _ < N; _++) {
        int __a = random_int(-2048, 2048);
        int __b = random_int(-2048, 2048);
        if (__b == 0)
            continue;
        int __product = __a * __b;

        Fixed a(__a);
        Fixed b(__b);
        Fixed product = a * b;
        // Fixed quotient = a / b;

        assert(product.toInt() == __product);
        //  assert(quotient == Fixed(__a / __b));
    }

    std::cout << "stochastic test float *// ok\n";
}

static float random_float(float low, float hi) {
    float range = hi - low;
    return low +
           static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / range));
}

static int32_t random_int(int32_t low, int32_t hi) {
    uint32_t range = hi - low;

    return low + static_cast<int32_t>(rand() % range);
}

static bool float_eq(float a, float b, float e) {
    return std::fabs(a - b) < e;
}
