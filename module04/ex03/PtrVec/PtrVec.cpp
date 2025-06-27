#include "PtrVec.hpp"

#include <cassert>

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

void PtrVec::grow() {
    if (this->data == NULL) {
        this->data = new Ptr[PtrVec::baseSize];
        this->capacity = PtrVec::baseSize;
        this->length = 0;
        return;
    }

    const Size newSize =
        1 + static_cast<Size>(PtrVec::growingFactor *
                              static_cast<float>(this->length));
    Ptr* newData = new Ptr[newSize];
    this->capacity = newSize;

    for (Size i = 0; i < this->length; ++i) {
        newData[i] = data[i];
    }

    delete[] this->data;
    this->data = newData;
}

void PtrVec::pushBack(void* p) {
    if (this->length >= this->capacity) {
        this->grow();
        assert(this->length < this->capacity);
    }

    this->data[this->length++] = p;
}

bool PtrVec::isEmpty() const {
    return this->length == 0;
}

PtrVec::Size PtrVec::size() const {
    return this->length;
}

bool PtrVec::contains(void* p) const {
    for (Size i = 0; i < this->length; ++i) {
        if (this->data[i] == p) {
            return true;
        }
    }

    return false;
}

void PtrVec::clear() {
    this->length = 0;
}

PtrVec::Ptr PtrVec::operator[](Size i) const {
    return this->data[i];
}
