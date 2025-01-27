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
    int raw = this->getRawBits() * other.getRawBits();
    raw /= (1 << Fixed::fractional_digits);
    Fixed out;
    out.setRawBits(raw);
    return out;
}

Fixed Fixed::operator/(const Fixed& other) const {
    int raw = this->getRawBits() / other.getRawBits();
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
