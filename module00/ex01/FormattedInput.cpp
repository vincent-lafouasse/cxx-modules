#include "FormattedInput.h"

#include <iostream>

namespace FormattedInput {
std::string get_string_or_exit(std::istream& stream) {
    std::string out;

    stream >> out;
    if (stream.eof()) {
        std::cout << std::endl;
        std::exit(EXIT_SUCCESS);
    }

    return out;
}
}  // namespace FormattedInput
