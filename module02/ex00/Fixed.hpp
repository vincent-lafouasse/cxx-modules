#pragma once

#include <cstdint>
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
	uint8_t bits;
	static const std::size_t depth = 8;
};
