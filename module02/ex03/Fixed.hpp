#pragma once

#include <iostream>

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed&);
    explicit Fixed(int);
    explicit Fixed(float);
    Fixed& operator=(const Fixed&);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int);
    float toFloat() const;
    int toInt() const;

    static Fixed& max(Fixed&, Fixed&);
    static Fixed& min(Fixed&, Fixed&);
    static const Fixed& max(const Fixed&, const Fixed&);
    static const Fixed& min(const Fixed&, const Fixed&);

    bool operator>(const Fixed&) const;
    bool operator<(const Fixed&) const;
    bool operator>=(const Fixed&) const;
    bool operator<=(const Fixed&) const;
    bool operator==(const Fixed&) const;
    bool operator!=(const Fixed&) const;

    Fixed operator+(const Fixed&) const;
    Fixed operator-(const Fixed&) const;
    Fixed operator*(const Fixed&) const;
    Fixed operator/(const Fixed&) const;

    Fixed operator++(int);
    Fixed operator--(int);
    Fixed& operator++();
    Fixed& operator--();

   private:
    int bits;
    static const std::size_t fractional_digits = 8;

    static int scaling_factor();
};

std::ostream& operator<<(std::ostream&, const Fixed&);
