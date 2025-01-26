#pragma once

#include <cstddef>

class Fixed {
public:
	Fixed();
	Fixed(Fixed& other);
	Fixed& operator=(Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int bits;
	static const std::size_t fractional_digits = 8;
};
