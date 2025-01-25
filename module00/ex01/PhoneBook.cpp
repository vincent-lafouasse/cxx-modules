#include "PhoneBook.hpp"

#include <iostream>

PhoneBook::PhoneBook() : sz(0) {}

void PhoneBook::process_command(Command command) {
    if (command.kind == Command::Add) {
        this->prompt_and_add_contact();
    } else if (command.kind == Command::Search) {
        this->display();
        this->prompt_and_display_contact();
    }
}

void PhoneBook::prompt_and_add_contact() {
    Contact contact;
    while (!contact.is_valid()) {
        contact = Contact::from_user();
    }
    this->push(contact);
}

void PhoneBook::prompt_and_display_contact() const {
    std::string index_string;
    std::cin >> index_string;
    std::size_t index;
    try {
        index = std::stoul(index_string, NULL, 10);
    } catch (...) {
        std::cout << "No" << std::endl;
        return;
    }
    if (index >= this->sz) {
        std::cout << "No" << std::endl;
    } else {
        data[index].display();
    }
}

void PhoneBook::push(const Contact& to_add) {
    if (sz == PHONE_BOOK_SZ) {
        data[sz - 1] = to_add;
    } else {
        data[sz] = to_add;
        sz++;
    }
}

void PhoneBook::display() const {
    for (std::size_t i = 0; i < this->sz; i++) {
        std::cout << i << " | ";
        data[i].display_one_line();
    }
}
