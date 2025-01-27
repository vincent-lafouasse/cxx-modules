#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed& other) const {
    int raw = this->getRawBits() + other.getRawBits();
    Fixed out;
    out.setRawBits(raw);
    return out;
}

Fixed Fixed::operator-(const Fixed& other) const {
    int raw = this->getRawBits() - other.getRawBits();
    Fixed out;
    out.setRawBits(raw);
    return out;
}

Fixed Fixed::operator*(const Fixed& other) const {
    int raw = (this->bits * other.bits) / (1 << Fixed::fractional_digits);
    Fixed out;
    out.setRawBits(raw);
    return out;
}

Fixed Fixed::operator/(const Fixed& other) const {
    int raw = (this->bits * (1 << Fixed::fractional_digits)) / other.bits;
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

Fixed& max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

Fixed& min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

const Fixed& max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

const Fixed& min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}
