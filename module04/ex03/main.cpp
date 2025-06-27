#include <cassert>
#include <iostream>

#include "Character/Character.hpp"
#include "Materia/Ice.hpp"

int main() {
    ICharacter* character = new Character("poss");
    std::cout << "Hello my name is " << character->getName() << std::endl;

    AMateria* ice = new Ice();
    std::cout << "This is a " << ice->getType() << " materia" << std::endl;

    AMateria* iceAlso = ice->clone();
    assert(ice != iceAlso);

    character->equip(ice);
    character->equip(iceAlso);

    ICharacter* victim = new Character("poor victim");

    for (std::size_t i = 0; i < 4; ++i) {
        std::cout << i << '\t';
        character->use(i, *victim);
    }

    delete character;
    delete victim;
}
