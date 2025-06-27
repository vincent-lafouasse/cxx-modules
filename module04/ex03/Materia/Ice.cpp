#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& o) : AMateria(o.type) {}

Ice& Ice::operator=(const Ice& other) {
    this->type = other.type;
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& c) {
    std::cout << "* heals " << c.getName() << "'s wounds *\n";
}
