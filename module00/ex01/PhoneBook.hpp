#pragma once

#include "Contact.hpp"

enum class Command {
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

  static constexpr size_t N = 8;
  Contact data[N];
};
