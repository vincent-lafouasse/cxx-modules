#pragma once

#include <istream>
#include <string>

namespace FormattedInput {
std::string get_string_or_exit(std::istream& stream);
}  // namespace FormattedInput
