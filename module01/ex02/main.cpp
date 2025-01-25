#include <iostream>
#include <string>

int main() {
    std::string s = "HI THIS IS BRAIN";
    std::string* stringPTR = &s;
    std::string& stringREF = s;

    std::cout << "address s:\t\t" << &s << '\n';
    std::cout << "address stringPTR:\t" << stringPTR << '\n';
    std::cout << "address stringREF:\t" << &stringREF << '\n';

    std::cout << "value s:\t\t" << s << '\n';
    std::cout << "value stringPTR:\t" << *stringPTR << '\n';
    std::cout << "value stringREF:\t" << stringREF << '\n';
}
