#pragma once

#include <cstddef>

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);

   private:
    int bits;
    static const std::size_t fractional_digits = 8;
};
