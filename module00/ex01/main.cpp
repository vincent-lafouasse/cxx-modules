#include "PhoneBook.hpp"

int main() {
    PhoneBook phone_book;

    PhoneBook::Command command = PhoneBook::prompt_user();
    phone_book.process_command(command);
}
