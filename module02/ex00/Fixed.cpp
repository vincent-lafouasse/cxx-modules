#include "Fixed.hpp"
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

Fixed& Fixed::operator=(const Fixed& other) {
    LOG();
    this->bits = other.bits;
    return *this;
}

Fixed::~Fixed() {
    LOG();
}

int Fixed::getRawBits() const {
    LOG();
    return this->bits;
}

void Fixed::setRawBits(int const raw) {
    LOG();
    this->bits = raw;
}
