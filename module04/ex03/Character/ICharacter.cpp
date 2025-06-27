#include "ICharacter.hpp"

ICharacter::ICharacter() {}

ICharacter::ICharacter(const ICharacter&) {}

ICharacter& ICharacter::operator=(const ICharacter&) {
    return *this;
}

ICharacter::~ICharacter() {}
