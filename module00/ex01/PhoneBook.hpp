#pragma once

#include "Command.hpp"
#include "Contact.hpp"

#define PHONE_BOOK_SZ 8

class PhoneBook {
   public:
    PhoneBook();
    void process_command(Command command);

   private:
   void prompt_and_add_contact();
   void prompt_and_display_contact() const;
    void push(const Contact& to_add);
    void display() const;

    Contact data[PHONE_BOOK_SZ];
    std::size_t sz;
};
