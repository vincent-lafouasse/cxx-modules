#include <iostream>

#include "Character/Character.hpp"
#include "Materia/Ice.hpp"

int main() {
    ICharacter* character = new Character("poss");
    std::cout << "Hello my name is " << character->getName() << std::endl;

    AMateria* ice = new Ice();
    std::cout << "This is a " << ice->getType() << " materia" << std::endl;

    character->equip(ice);
    character->use(0, *character);

    delete character;
    delete ice;
}
