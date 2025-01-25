#include "PhoneBook.hpp"

#include <iostream>

PhoneBook::PhoneBook() {}

Command PhoneBook::prompt_user() {
    std::cout << "give me a thing" << std::endl;
    return Add;
}

void PhoneBook::process_command(Command command) {}
