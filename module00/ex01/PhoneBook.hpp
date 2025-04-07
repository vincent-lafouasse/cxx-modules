#pragma once

#include "Command.hpp"
#include "Contact.hpp"

class PhoneBook {
   public:
    PhoneBook();
    void process_command(Command command);

   private:
    void prompt_and_add_contact();
    void prompt_and_display_contact() const;
    void push(const Contact& to_add);
    void display() const;

    static const std::size_t capacity = 8;
    Contact contacts[PhoneBook::capacity];
    std::size_t sz;
    std::size_t oldest;
};
