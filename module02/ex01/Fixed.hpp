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

   private:
    int bits;
    static const std::size_t fractional_digits = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed&);
