#include "Fixed.hpp"
#include <math.h> // how the fuck do we not have std::roundf in C++98
#include <iostream>

Fixed::Fixed() : bits(0) {}

Fixed::Fixed(const Fixed& other) : bits(other.bits) {}

Fixed::Fixed(int i) : bits(i * Fixed::scaling_factor()) {}

Fixed::Fixed(float f)
    : bits(static_cast<int>(
          roundf(f * static_cast<float>(Fixed::scaling_factor())))) {}

Fixed& Fixed::operator=(const Fixed& other) {
    this->bits = other.bits;
    return *this;
}

Fixed::~Fixed() {}

float Fixed::toFloat() const {
    return static_cast<float>(this->bits) /
           static_cast<float>(Fixed::scaling_factor());
}

int Fixed::toInt() const {
    return this->bits / Fixed::scaling_factor();
}

int Fixed::getRawBits() const {
    return this->bits;
}

void Fixed::setRawBits(int const raw) {
    this->bits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& self) {
    os << self.toFloat();
    return os;
}

int Fixed::scaling_factor() {
    return (1 << Fixed::fractional_digits);
}
