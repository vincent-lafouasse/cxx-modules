#include "PhoneBook.hpp"

#include <cstdlib>
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
    long index;
    while (1) {
        std::string index_string;
        std::cout << "> > ";
        std::cout.flush();
        std::cin >> index_string;
        char* end_ptr;
        index = std::strtol(index_string.c_str(), &end_ptr, 10);

        if (*end_ptr != '\0') {
            std::cout << "No" << std::endl;
            continue;
        }
        if (static_cast<std::size_t>(index) >= this->sz || index < 0) {
            std::cout << "No" << std::endl;
            continue;
        }
        break;
    }

    data[index].display();
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
        data[i].display_one_line(i);
    }
}
