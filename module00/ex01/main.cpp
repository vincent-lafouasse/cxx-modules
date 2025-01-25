#include "PhoneBook.hpp"

#include <iostream>

static void print_prompt();

int main() {
    PhoneBook phone_book;

    print_prompt();
    for (std::string line; std::getline(std::cin, line);) {
        Command command(line);
        if (command.kind == Command::Exit) {
            break;
        }
        phone_book.process_command(command);
        print_prompt();
    }
}

static void print_prompt() {
    std::cout << "> ";
    std::cout.flush();
}
