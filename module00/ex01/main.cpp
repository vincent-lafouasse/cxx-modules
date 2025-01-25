#include "PhoneBook.hpp"

#include <iostream>

static void print_prompt();

int main() {
    PhoneBook phone_book;

    while (1) {
        std::string line;
        if (std::cin.eof())
            break;
        std::cout << "> ";
        std::cin >> line;
        if (line.empty())
            continue;
        Command command(line);
        if (command.kind == Command::Exit) {
            break;
        }
        phone_book.process_command(command);
    }
}

static void print_prompt() {
    std::cout << "> ";
    std::cout.flush();
}
