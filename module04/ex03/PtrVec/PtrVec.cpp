#include "PtrVec.hpp"

const PtrVec::Size PtrVec::baseSize = 4;
const float PtrVec::growingFactor = 1.5f;

PtrVec::PtrVec() : length(0), capacity(0), data(NULL) {}

PtrVec::PtrVec(const PtrVec& o) : data(NULL) {
    *this = o;
}

PtrVec& PtrVec::operator=(const PtrVec& other) {
    if (this == &other) {
        return *this;
    }

    if (this->data != NULL) {
        delete[] this->data;
    }

    if (other.data == NULL) {
        this->data = NULL;
        this->length = 0;
        this->capacity = 0;
        return *this;
    }

    this->data = new Ptr[other.length];
    this->length = other.length;
    this->capacity = other.length;
    for (Size i = 0; i < other.length; ++i) {
        this->data[i] = other.data[i];
    }

    return *this;
}

PtrVec::~PtrVec() {
    delete[] data;
}
