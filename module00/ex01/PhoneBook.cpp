#include "PhoneBook.hpp"

#include <iostream>

PhoneBook::PhoneBook() {}

Command PhoneBook::prompt_user() {
    std::string input;

    std::cin >> input;
    return Command(input);
}

void PhoneBook::process_command(Command command) {
    if (command.kind == Command::Add) {
        std::cout << "add" << std::endl;
    } else if (command.kind == Command::Search) {
        std::cout << "search" << std::endl;
    } else if (command.kind == Command::Exit) {
        std::cout << "exit" << std::endl;
    } else {
        return;
    }
}
