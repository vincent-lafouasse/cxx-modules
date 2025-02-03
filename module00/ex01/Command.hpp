#pragma once

#include <string>

class Command {
   public:
    enum Kind { Add, Search, Exit, None };
    explicit Command(const std::string& s);

    Command::Kind kind;
};
