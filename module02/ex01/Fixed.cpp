#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const char* default_ctor_msg = "Default constructor called\n";
const char* copy_ctor_msg = "Copy constructor called\n";
const char* copy_assig_op_msg = "Copy assignment operator called\n";
const char* int_ctor_msg = "Int constructor called";
const char* float_ctor_msg = "Float constructor called";
const char* dtor_msg = "Destructor called\n";
const char* get_msg = "getRawBits member function called\n";
const char* set_msg = "setRawBits member function called\n";

Fixed::Fixed() : bits(0) {
    std::cout << default_ctor_msg;
}

Fixed::Fixed(const Fixed& other) : bits(other.bits) {
    std::cout << copy_ctor_msg;
}

Fixed::Fixed(int i) : bits(i * (1 << Fixed::fractional_digits)) {
    std::cout << int_ctor_msg;
}

Fixed::Fixed(float f)
    : bits(static_cast<int>(f * (1 << Fixed::fractional_digits))) {
    std::cout << float_ctor_msg;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << copy_assig_op_msg;
    this->bits = other.bits;
    return *this;
}

Fixed::~Fixed() {
    std::cout << dtor_msg;
}

float Fixed::toFloat() const {
    return static_cast<float>(bits) /
           static_cast<float>(1 << Fixed::fractional_digits);
}

int Fixed::toInt() const {
    return static_cast<int>(this->toFloat());
}

int Fixed::getRawBits() const {
    std::cout << get_msg;
    return bits;
}

void Fixed::setRawBits(int const raw) {
    std::cout << set_msg;
    bits = raw;
}
