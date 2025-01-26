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

    std::ostream& operator<<(std::ostream& os) const {
      os << this->toFloat();
      return os;
   }

    int getRawBits() const;
    void setRawBits(int);
    float toFloat() const;
    int toInt() const;

   private:
    int bits;
    static const std::size_t fractional_digits = 8;
};
