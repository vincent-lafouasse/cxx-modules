#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : type(type) {}

std::string const& AMateria::getType() const {
    return this->type;
}

AMateria::AMateria() {}

AMateria::AMateria(const AMateria& o) : type(o.type) {}

AMateria& AMateria::operator=(const AMateria& o) {
    this->type = o.type;
    return *this;
}
AMateria::~AMateria() {}
