#include "Fixed.hpp"

Fixed::Fixed() : bits(0) {}
Fixed::Fixed(Fixed& other) : bits(other.bits) {}
Fixed& Fixed::operator=(Fixed& other) {
    this->bits = other.bits;
    return *this;
}
Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return bits;
}
void Fixed::setRawBits(int const raw) {
    bits = raw;
}
