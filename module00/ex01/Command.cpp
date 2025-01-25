#include "Command.hpp"

Command::Command(const std::string& s) {
    if (s == "ADD") {
        kind = Add;
    } else if (s == "SEARCH") {
        kind = Search;
    } else if (s == "EXIT") {
        kind = Exit;
    } else {
        kind = None;
    }
}
