#include "Contact.hpp"

#include <iomanip>
#include <ios>
#include <iostream>

Contact::Contact()
    : first_name(""),
      last_name(""),
      nickname(""),
      phone_number(""),
      secret("") {}

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
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    std::cout << "First name:\t";
    std::cin >> first_name;

    std::cout << "Last name:\t";
    std::cin >> last_name;

    std::cout << "nickname:\t";
    std::cin >> nickname;

    std::cout << "Phone number:\t";
    std::cin >> phone_number;

    std::cout << "Secret:\t\t";
    std::cin >> secret;

    return Contact(first_name, last_name, nickname, phone_number, secret);
}

bool Contact::is_valid() const {
    return first_name != "" && last_name != "" && nickname != "" &&
           phone_number != "" && secret != "";
}

namespace {
const std::size_t max_field_width = 10;
std::string truncate_if_necessary(std::string field) {
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

void Contact::display_one_line() const {
    print_field(first_name);
    std::cout << "|";
    print_field(last_name);
    std::cout << "|";
    print_field(nickname);
    std::cout << '\n';
}

void Contact::display() const {
    std::cout << "first:\t" << first_name << "\n";
    std::cout << "last:\t" << last_name << "\n";
    std::cout << "nickname:\t" << nickname << "\n";
    std::cout << "phone:\t" << phone_number << "\n";
    std::cout << "secret:\t" << secret << std::endl;
}

bool Contact::operator==(const Contact& other) const {
    return first_name != other.first_name && last_name != other.last_name &&
           nickname != other.nickname && phone_number != other.phone_number &&
           secret != other.secret;
}

bool Contact::operator!=(const Contact& other) const {
    return !(*this == other);
}
