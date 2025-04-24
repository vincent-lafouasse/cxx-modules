#include "PhoneBook.hpp"

#include <cstdlib>
#include <iostream>

#include "FormattedInput.h"

PhoneBook::PhoneBook() : sz(0), oldest(0) {}

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

    do {
        contact = Contact::from_user();
    } while (!contact.is_valid());
    this->push(contact);
}

void PhoneBook::prompt_and_display_contact() const {
    long index;
    while (true) {
        std::cout << "> > ";
        std::string index_string = FormattedInput::get_string_or_exit(std::cin);

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

    contacts[index].display();
}

void PhoneBook::push(const Contact& to_add) {
    if (this->sz == PhoneBook::capacity) {
        this->contacts[this->oldest] = to_add;
        this->oldest = (this->oldest + 1) % PhoneBook::capacity;
    } else {
        this->contacts[sz] = to_add;
        this->sz++;
    }
}

void PhoneBook::display() const {
    for (std::size_t i = 0; i < this->sz; i++) {
        contacts[i].display_one_line(i);
    }
}

PhoneBook::Command::Command(const std::string& s) {
    if (s == "ADD") {
        kind = Add;
    } else if (s == "SEARCH") {
        kind = Search;
    } else if (s == "EXIT") {
        kind = Exit;
    } else {
        kind = None;
    }
}
