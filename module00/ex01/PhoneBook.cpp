#include "PhoneBook.hpp"

#include <iostream>

PhoneBook::PhoneBook() : sz(0) {}

Command PhoneBook::prompt_user() {
    std::string input;

    std::cin >> input;
    return Command(input);
}

void PhoneBook::process_command(Command command) {
    if (command.kind == Command::Add) {
        Contact contact;
        while (!contact.is_valid()) {
            contact = Contact::from_user();
        }
        contact.display();
    } else if (command.kind == Command::Search) {
        std::cout << "search" << std::endl;
    } else if (command.kind == Command::Exit) {
        std::cout << "exit" << std::endl;
    } else {
        return;
    }
}

void PhoneBook::push(const Contact& to_add) const {
    if (sz == PHONE_BOOK_SZ) {
        data[sz - 1] = to_add;
    } else {
        data[sz] = to_add;
        sz++;
    }
}
