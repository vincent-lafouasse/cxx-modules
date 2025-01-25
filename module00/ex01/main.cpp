#include "PhoneBook.hpp"

int main() {
    PhoneBook phone_book;

    while (1) {
        Command command = PhoneBook::prompt_user();
        if (command.kind == Command::Exit) {
            break;
        }
        phone_book.process_command(command);
    }
}
