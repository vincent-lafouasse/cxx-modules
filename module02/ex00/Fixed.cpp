#include "Fixed.hpp"
#include <iostream>

namespace {
const char* default_ctor_msg = "Default constructor called\n";
const char* copy_ctor_msg = "Copy constructor called\n";
const char* copy_assig_op_msg = "Copy assignment operator called\n";
const char* dtor_msg = "Destructor called\n";
const char* get_msg = "getRawBits member function called\n";
const char* set_msg = "setRawBits member function called\n";
}  // namespace

Fixed::Fixed() : bits(0) {
    std::cout << default_ctor_msg;
}

Fixed::Fixed(const Fixed& other) : bits(other.getRawBits()) {
    std::cout << copy_ctor_msg;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << copy_assig_op_msg;
    this->bits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << dtor_msg;
}

int Fixed::getRawBits() const {
    std::cout << get_msg;
    return bits;
}

void Fixed::setRawBits(int const raw) {
    std::cout << set_msg;
    bits = raw;
}
