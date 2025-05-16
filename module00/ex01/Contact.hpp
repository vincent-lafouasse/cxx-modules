#pragma once

#include <string>

class Contact {
   public:
    Contact();
    static Contact from_user();  // prompts user and fills in Contact
    bool is_valid() const;       // checks that all fields are non-empty
    void display() const;
    void display_one_line(std::size_t index) const;

    const std::string& get_first_name();
    const std::string& get_last_name();
    const std::string& get_nickname();
    const std::string& get_phone_number();
    const std::string& get_secret();

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
