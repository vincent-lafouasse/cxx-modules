#pragma once

#include <iostream>

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed&);
    Fixed(int);
    Fixed(float);
    Fixed& operator=(const Fixed&);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int);
    float toFloat() const;
    int toInt() const;

    static Fixed& max(Fixed&, Fixed&);
    static Fixed& max(const Fixed&, const Fixed&);
    static Fixed& min(Fixed&, Fixed&);
    static Fixed& min(const Fixed&, const Fixed&);

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

    Fixed operator++(int) const;
    Fixed operator--(int) const;
    Fixed& operator++() const;
    Fixed& operator--() const;

    friend std::ostream& operator<<(std::ostream&, const Fixed&);

   private:
    int bits;
    static const std::size_t fractional_digits = 8;
};
