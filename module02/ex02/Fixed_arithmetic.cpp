#include "Fixed.hpp"

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
    int raw = this->bits * other.bits / Fixed::scaling_factor();
    Fixed out;
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
    int raw = this->bits * Fixed::scaling_factor() / other.bits;
    Fixed out;
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
    return (*this > o) || (*this == o);
}

bool Fixed::operator<=(const Fixed& o) const {
    return (*this < o) || (*this == o);
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
