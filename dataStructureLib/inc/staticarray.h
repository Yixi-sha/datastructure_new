#ifndef STATICARRAY_H
#define STATICARRAY_H

#include "array.h"

namespace yixi {

template <typename T, int N>
class StaticArray : public Array<T>
{
protected:
    T i_memArray[N];

public:
    StaticArray();
    StaticArray(const StaticArray<T, N>& obj);
    StaticArray<T,N>& operator = (const StaticArray<T, N>& obj);

    virtual int size() const;

};

}





#include "../src/staticarray.cpp"

#endif // STATICARRAY_H
