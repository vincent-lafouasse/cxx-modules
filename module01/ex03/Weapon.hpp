#pragma once

#include <string>

class Weapon {
public:
	const std::string& getType() const;
	void setType();
private:
	std::string type;
};
