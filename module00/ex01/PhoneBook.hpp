#pragma once

#include "Contact.hpp"

#define PHONE_BOOK_SZ 8

enum Command {
  Add,
  Search,
  Exit,
};

class PhoneBook {
public:
  PhoneBook();
  static Command prompt_user();
  void process_command(Command command);

private:
  void push(const Contact &to_add) const;
  void display() const;

  Contact data[PHONE_BOOK_SZ];
};
