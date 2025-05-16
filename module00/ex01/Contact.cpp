#include "Contact.hpp"

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
    const std::string first_name = FormattedInput::get_string_or_exit(std::cin);

    std::cout << "Last name:\t";
    const std::string last_name = FormattedInput::get_string_or_exit(std::cin);

    std::cout << "nickname:\t";
    const std::string nickname = FormattedInput::get_string_or_exit(std::cin);

    std::cout << "Phone number:\t";
    const std::string phone_number =
        FormattedInput::get_string_or_exit(std::cin);

    std::cout << "Secret:\t\t";
    const std::string secret = FormattedInput::get_string_or_exit(std::cin);

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

void Contact::display_one_line(const std::size_t index) const {
    if (!this->is_valid()) {
        std::cout << "Invalid contact\n";
        return;
    }

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
    if (!this->is_valid()) {
        std::cout << "Invalid contact\n";
        return;
    }
    std::cout << std::left;
    std::cout << std::setw(11) << "first:" << first_name << "\n";
    std::cout << std::setw(11) << "last:" << last_name << "\n";
    std::cout << std::setw(11) << "nickname:" << nickname << "\n";
    std::cout << std::setw(11) << "phone:" << phone_number << "\n";
    std::cout << std::setw(11) << "secret:" << secret << std::endl;
}

const std::string& Contact::get_first_name() {
    return this->first_name;
}

const std::string& Contact::get_last_name() {
    return this->last_name;
}

const std::string& Contact::get_nickname() {
    return this->nickname;
}

const std::string& Contact::get_phone_number() {
    return this->phone_number;
}

const std::string& Contact::get_secret() {
    return this->secret;
}
