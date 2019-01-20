#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "array.h"

namespace yixi {

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int i_size;

    void memCopy(T* dis, T* src, int N);
    void update(T* newMem, int newSize);
public:
    DynamicArray(int size = 0);
    DynamicArray(const DynamicArray<T>& obj);

    DynamicArray<T>& operator =(const DynamicArray<T>& obj);
    virtual int size() const;
    bool reSize(int size);

    ~DynamicArray();

};

}

#include "../src/dynamicarray.cpp"

#endif // DYNAMICARRAY_H
