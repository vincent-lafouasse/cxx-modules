#pragma once

#include <string>
#include <utility>

#include "AForm.hpp"

class Intern {
private:
   typedef AForm* (*formMaker)(const std::string& target);
   static const std::size_t n = 3;
   static const std::pair<const char*, formMaker> factories[n];
};
