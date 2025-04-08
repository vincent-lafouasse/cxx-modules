#include <iostream>

#include "FormattedInput.h"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phone_book;

    while (true) {
        std::cout << "> ";
        std::string line = FormattedInput::get_string_or_exit(std::cin);
        if (line.empty())
            continue;
        Command command(line);
        if (command.kind == Command::Exit) {
            break;
        }
        phone_book.process_command(command);
    }
}
