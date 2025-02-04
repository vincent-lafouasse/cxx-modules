#include "PhoneBook.hpp"

#include <iostream>

int main() {
    PhoneBook phone_book;

    while (true) {
        std::string line;
        std::cout << "> ";
        std::cin >> line;
        if (std::cin.eof())
            break;
        if (line.empty())
            continue;
        Command command(line);
        if (command.kind == Command::Exit) {
            break;
        }
        phone_book.process_command(command);
    }
}
