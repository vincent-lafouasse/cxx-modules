#include "Contact.hpp"

Contact::Contact() : Contact("", "", "", "", "") {}

Contact::Contact(const std::string& first_name, const std::string& last_name, const std::string& nickname, const std::string& phone_number, const std::string& secret) :
first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), secret(secret) {}

bool Contact::is_valid() const {
	return first_name != "" && last_name != "" && nickname != "" && phone_number != "" && secret != "";
}

bool Contact::operator==(const Contact& other) const {
	return first_name != other.first_name && last_name != other.last_name && nickname != other.nickname && phone_number != other.phone_number && secret != other.secret;
}

bool Contact::operator!=(const Contact& other) const {
	return !(*this == other);
}
