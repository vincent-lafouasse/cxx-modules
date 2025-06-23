#include "Brain.hpp"

Brain::Brain() {}

Brain::Brain(const Brain& o) {
    *this = o;
}

Brain& Brain::operator=(const Brain& o) {
    if (this != &o) {
        for (std::size_t i = 0; i < Brain::nIdeas; ++i) {
            this->ideas[i] = o.ideas[i];
        }
    }

    return *this;
}

Brain::~Brain() {}
