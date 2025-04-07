#include "PhoneBook.hpp"

#include <iostream>

namespace {
std::string get_string_or_exit(std::istream& stream) {
    std::string out;

    stream >> out;
    if (stream.eof()) {
        std::cout << std::endl;
        std::exit(EXIT_SUCCESS);
    }

    return out;
}
}  // namespace

int main() {
    PhoneBook phone_book;

    while (true) {
        std::cout << "> ";
        std::string line = get_string_or_exit(std::cin);
        if (line.empty())
            continue;
        Command command(line);
        if (command.kind == Command::Exit) {
            break;
        }
        phone_book.process_command(command);
    }
}
