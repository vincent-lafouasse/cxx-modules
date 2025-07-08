#include <cassert>
#include <iostream>

#include "Character/Character.hpp"
#include "Materia/Cure.hpp"
#include "Materia/Ice.hpp"
#include "Materia/MateriaSource.hpp"

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
    me->equip(new Cure());

    ICharacter* racc = new Character("racc");

    for (int i = 0; i < 4; ++i) {
        std::clog << i << '\t';
        me->use(i, *racc);
    }

    delete me;
    delete racc;
}

void givenTest() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

int main() {
    assertBasicConstruction();
    assertCloneIsDeep();

    memcheck::assertCharacterOwnsMaterias();
    memcheck::assertCharacterInventoryIsOverflowProof();

    checkMateriaLogs();

    givenTest();
}
