#ifndef ARRAY_H
#define ARRAY_H
#include "object.h"

namespace yixi {

template <typename T>
class Array : public Object
{
protected:
    T* i_mem;
public:
    bool set(int pos, const T& obj);
    bool get(int pos,T& obj) const;
    T& get(int pos);
    T get(int pos) const;
    virtual int size() const = 0;

    T& operator[](int pos);
    T operator [](int pos) const;

};
}

#include "../src/array.cpp"

#endif // ARRAY_H
