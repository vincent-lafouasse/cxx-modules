#include "PhoneBook.hpp"

#include <iostream>

int main() {
    PhoneBook phone_book;
    std::string line;

    while (std::cout << "> ", std::getline(std::cin, line)) {
        Command command(line);
        if (command.kind == Command::Exit) {
            break;
        }
        phone_book.process_command(command);
    }
}
