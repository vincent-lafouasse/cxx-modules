#include "PhoneBook.hpp"

#include <iostream>

int main() {
    PhoneBook phone_book;

    while (true) {
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
