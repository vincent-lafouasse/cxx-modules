#pragma once

#include <string>

class Command {
   public:
    enum Kind {
        Add,
        Search,
        Exit,
        None,
    };
   Command(const std::string& s);

   Command::Kind kind;
};
