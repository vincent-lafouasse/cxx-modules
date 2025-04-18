#include "Contact.hpp"

#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>

#include "FormattedInput.h"

Contact::Contact() {}

Contact::Contact(const std::string& first_name,
                 const std::string& last_name,
                 const std::string& nickname,
                 const std::string& phone_number,
                 const std::string& secret)
    : first_name(first_name),
      last_name(last_name),
      nickname(nickname),
      phone_number(phone_number),
      secret(secret) {}

Contact Contact::from_user() {
    std::cout << "First name:\t";
    std::string first_name = FormattedInput::get_string_or_exit(std::cin);

    std::cout << "Last name:\t";
    std::string last_name = FormattedInput::get_string_or_exit(std::cin);

    std::cout << "nickname:\t";
    std::string nickname = FormattedInput::get_string_or_exit(std::cin);

    std::cout << "Phone number:\t";
    std::string phone_number = FormattedInput::get_string_or_exit(std::cin);

    std::cout << "Secret:\t\t";
    std::string secret = FormattedInput::get_string_or_exit(std::cin);

    return Contact(first_name, last_name, nickname, phone_number, secret);
}

bool Contact::is_valid() const {
    return !(first_name.empty() || last_name.empty() || nickname.empty() ||
             phone_number.empty() || secret.empty());
}

namespace {
const std::size_t max_field_width = 10;

std::string truncate_if_necessary(const std::string& field) {
    if (field.length() <= max_field_width) {
        return field;
    }

    return field.substr(0, max_field_width - 1) + ".";
}

void print_field(const std::string& field) {
    std::cout << std::setw(max_field_width) << std::right;
    std::cout << truncate_if_necessary(field);
}
}  // namespace

void Contact::display_one_line(std::size_t index) const {
    std::cout << "|";
    std::cout << std::setw(max_field_width) << std::right;
    std::cout << index;
    std::cout << "|";
    print_field(first_name);
    std::cout << "|";
    print_field(last_name);
    std::cout << "|";
    print_field(nickname);
    std::cout << "|\n";
}

void Contact::display() const {
    std::cout << std::left;
    std::cout << std::setw(11) << "first:" << first_name << "\n";
    std::cout << std::setw(11) << "last:" << last_name << "\n";
    std::cout << std::setw(11) << "nickname:" << nickname << "\n";
    std::cout << std::setw(11) << "phone:" << phone_number << "\n";
    std::cout << std::setw(11) << "secret:" << secret << std::endl;
}
