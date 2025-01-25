#pragma once

#include <string>

class Zombie {
public:
	Zombie(const std::string& name);
	void announce() const;

private:
	std::string name;
};
