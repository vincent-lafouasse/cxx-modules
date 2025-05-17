#include "Fixed.hpp"

#include <math.h>
#include <iostream>

namespace {
#define LOG() std::clog << __PRETTY_FUNCTION__ << std::endl;
}  // namespace

Fixed::Fixed() : bits(0) {
    LOG();
}

Fixed::Fixed(const Fixed& other) : bits(other.bits) {
    LOG();
}

Fixed::Fixed(int i) : bits(i * Fixed::scaling_factor()) {
    LOG();
}

Fixed::Fixed(float f) {
    LOG();
    const float value = f * static_cast<float>(Fixed::scaling_factor());
    this->bits = static_cast<int>(value);
}

Fixed& Fixed::operator=(const Fixed& other) {
    LOG();
    this->bits = other.bits;
    return *this;
}

Fixed::~Fixed() {
    LOG();
}

float Fixed::toFloat() const {
    return static_cast<float>(bits) /
           static_cast<float>(Fixed::scaling_factor());
}

int Fixed::toInt() const {
    return this->bits / Fixed::scaling_factor();
}

int Fixed::scaling_factor() {
    return static_cast<int>(1 << Fixed::fractional_digits);
}

int Fixed::getRawBits() const {
    LOG();
    return bits;
}

void Fixed::setRawBits(int const raw) {
    LOG();
    bits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& self) {
    os << self.toFloat();
    return os;
}
