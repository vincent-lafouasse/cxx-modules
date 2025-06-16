#include "Fixed.hpp"
#include <math.h>  // how the fuck do we not have std::roundf in C++98
#include <iostream>

Fixed::Fixed() : bits(0) {}

Fixed::Fixed(const Fixed& other) : bits(other.bits) {}

Fixed::Fixed(int i) : bits(i * Fixed::scaling_factor()) {}

Fixed::Fixed(float f) {
    const float value = f * static_cast<float>(Fixed::scaling_factor());
    this->bits = static_cast<int>(roundf(value));
}

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

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed out;
    int raw = this->getRawBits() + other.getRawBits();
    out.setRawBits(raw);
    return out;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed out;
    int raw = this->getRawBits() - other.getRawBits();
    out.setRawBits(raw);
    return out;
}

/*
    a = 15.20 -> R(a) = 1520 == a * 10^2
    b = 2.00  -> R(b) = 200  == b * 10^2

    S = 10^2 (ou 2^N == 1 << N)
    R(x) = x * S
*/

/*
    R(a * b) ?
    R(a * b) = (a * b) * S
    R(a) * R(b) = a * b * S^2
                = R(a * b) * S
    R(a * b) = R(a) * R(b) / S
*/
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed out;
    int raw = this->bits * other.bits / Fixed::scaling_factor();
    out.setRawBits(raw);
    return out;
}

/*
    R(a / b) ?
    R(a / b) = (a / b) * S
    R(a) / R(b) = (a * S) / (b * S) = a/b

    R(a / b) = (a / b) * S
             = (R(a) / R(b)) * S
             = R(a) * S / R(b)
*/
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed out;
    int raw = this->bits * Fixed::scaling_factor() / other.bits;
    out.setRawBits(raw);
    return out;
}

Fixed Fixed::operator++(int) {
    Fixed buffer(*this);
    bits++;
    return buffer;
}

Fixed Fixed::operator--(int) {
    Fixed buffer(*this);
    bits--;
    return buffer;
}

Fixed& Fixed::operator++() {
    bits++;
    return *this;
}

Fixed& Fixed::operator--() {
    bits--;
    return *this;
}

bool Fixed::operator==(const Fixed& o) const {
    return this->bits == o.bits;
}

bool Fixed::operator!=(const Fixed& o) const {
    return !(*this == o);
}

bool Fixed::operator>(const Fixed& o) const {
    return this->bits > o.bits;
}

bool Fixed::operator<(const Fixed& o) const {
    return this->bits < o.bits;
}

bool Fixed::operator>=(const Fixed& o) const {
    return !(*this < o);
}

bool Fixed::operator<=(const Fixed& o) const {
    return !(*this > o);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}
