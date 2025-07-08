#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Intern.hpp"

int main() {
    std::srand(std::time(0));

    Intern poss;

    AForm* robotomyPog = poss.makeForm("robotomy request", "poss");
    assert(robotomyPog != NULL);
    std::cout << *robotomyPog << std::endl;

    AForm* forestMaker = poss.makeForm("create shrubbery", "poss");
    assert(forestMaker != NULL);
    std::cout << *forestMaker << std::endl;

    AForm* pardon = poss.makeForm("presidential pardon", "poss");
    assert(pardon != NULL);
    std::cout << *pardon << std::endl;

    assert(poss.makeForm("just give me my money", "poss") == NULL);

    delete robotomyPog;
    delete forestMaker;
    delete pardon;
}
