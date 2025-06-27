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

   private:
    void grow();

    Size length;
    Size capacity;
    Ptr* data;

    static const Size baseSize;
    static const float growingFactor;
};
