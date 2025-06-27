#pragma once

#include <cstddef>

class PtrVec {
   public:
    typedef std::size_t Size;
    typedef void* Ptr;

    PtrVec();
    PtrVec(const PtrVec&);
    PtrVec& operator=(const PtrVec&);
    ~PtrVec();

    Ptr operator[](Size) const;  // unchecked, UB on out of bounds
    // Ptr at(Size) const; // checked, throws on out of bounds

    bool isEmpty() const;
    void clear();

    Size size() const;
    bool contains(void* p) const;

    void pushBack(void* p);

   private:
    void grow();

    Size length;
    Size capacity;
    Ptr* data;

    static const Size baseSize;
    static const float growingFactor;
};
