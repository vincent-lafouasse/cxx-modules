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
    return Fixed();
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed();
}

Fixed Fixed::operator++(int) {}

Fixed Fixed::operator--(int) {}

Fixed& Fixed::operator++() {
    bits++;
    return *this;
}

Fixed& Fixed::operator--() {
    bits--;
    return *this;
}
