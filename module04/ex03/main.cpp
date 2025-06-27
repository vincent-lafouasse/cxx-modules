#include <cassert>
#include <iostream>

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

namespace memcheck {
void assertCharacterOwnsMaterias() {
    ICharacter* character = new Character("poss");

    character->equip(new Ice());  // deleted by character
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());

    delete character;
}

void assertCharacterInventoryIsOverflowProof() {
    ICharacter* character = new Character("poss");

    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());
    character->equip(new Ice());

    delete character;
}
}  // namespace memcheck

void checkMateriaLogs() {
    ICharacter* me = new Character("poss");
    me->equip(new Ice());
    // character->equip(new Cure());

    ICharacter* racc = new Character("racc");

    for (int i = 0; i < 4; ++i) {
        std::clog << i << '\t';
        me->use(i, *racc);
    }

    delete me;
    delete racc;
}

int main() {
    assertBasicConstruction();
    assertCloneIsDeep();

    memcheck::assertCharacterOwnsMaterias();
    memcheck::assertCharacterInventoryIsOverflowProof();

    checkMateriaLogs();
}
