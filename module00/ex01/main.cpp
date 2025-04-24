#include <iostream>

#include "FormattedInput.h"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phone_book;

    while (true) {
        std::cout << "> ";
        const std::string line = FormattedInput::get_string_or_exit(std::cin);
        if (line.empty())
            continue;

        const PhoneBook::Command command(line);
        if (command.kind == PhoneBook::Command::Exit) {
            break;
        }

        phone_book.process_command(command);
    }
}
