#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& o) : AMateria(o.type) {}

Cure& Cure::operator=(const Cure& other) {
    this->type = other.type;
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& c) {
    std::cout << "* heals " << c.getName() << "'s wounds *\n";
}
