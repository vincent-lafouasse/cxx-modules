#pragma once

#include <cstddef>

class Fixed {
   public:
    Fixed() : bits(0) {}
    Fixed(Fixed& other) : bits(other.bits) {}
    Fixed& operator=(Fixed& other) {
        this->bits = other.bits;
        return *this;
    }
    ~Fixed() {}

    int getRawBits() const { return bits; }
    void setRawBits(int const raw) { bits = raw; }

   private:
    int bits;
    static const std::size_t fractional_digits = 8;
};
