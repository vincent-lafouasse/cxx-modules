#include <cassert>

#include "Character/Character.hpp"
#include "Materia/Ice.hpp"

// coerces conversion
bool stringEq(const std::string& s1, const std::string& s2) {
    return s1 == s2;
}

void assertBasicConstruction() {
    ICharacter* character = new Character("poss");
    assert(stringEq(character->getName(), "poss"));

    AMateria* ice = new Ice();
    assert(stringEq(ice->getType(), "ice"));

    delete character;
    delete ice;
}

void assertCloneIsDeep() {
    AMateria* ice = new Ice();
    AMateria* iceAlso = ice->clone();

    assert(ice != iceAlso);

    delete ice;
    delete iceAlso;
}

// meant to be memcheck'd
void assertCharacterOwnsMaterias() {
    ICharacter* character = new Character("poss");

    character->equip(new Ice());  // deleted by character
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());

    delete character;
}

int main() {
    assertBasicConstruction();
    assertCloneIsDeep();
    assertCharacterOwnsMaterias();
}
