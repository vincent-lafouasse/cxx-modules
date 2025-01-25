#pragma once

#include <string>

class Contact {
   public:
    Contact();
    static Contact from_user();  // prompts user and fills in Contact
    bool is_valid() const;       // checks that all fields are non empty
    void display() const;
    bool operator==(const Contact& other) const;
    bool operator!=(const Contact& other) const;

   private:
    Contact(const std::string& first_name,
            const std::string& last_name,
            const std::string& nickname,
            const std::string& phone_number,
            const std::string& secret);

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;
};
