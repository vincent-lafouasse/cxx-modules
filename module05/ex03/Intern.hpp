#pragma once

#include <string>
#include <utility>

#include "AForm.hpp"

class Intern {
public:
   Intern();
   Intern(const Intern&);
   Intern& operator=(const Intern&);
   ~Intern();

   AForm* makeForm(const std::string& name, const std::string& target) const;

private:
   typedef AForm* (*formMaker)(const std::string& target);
   static const std::size_t n = 3;
   static const std::pair<const char*, formMaker> factories[n];
};
