#ifndef _MY_VECTOR_H__
#define _MY_VECTOR_H__

namespace yixi{

template<typename T>

class MyVector{
private:
    T* element;
    T* firstFree;
    T* cap;

    void copy_from_other(const MyVector& obj);
    void free(T* addr, int size);
    void check_n_alloc(); // if do not have suffient room, it will alloc
    void reallocate();

public:
    MyVector();
    MyVector(const MyVector& obj);

    MyVector& operator = (const MyVector& obj);

    ~MyVector();

    T& operator [](int pos);
    T operator [](int pos) const;

    void push_back(const T& obj);
    int size() const;
    int capacity() const;
    T* begin();
    T* end();
};

}

#include "../src/myVector.cpp"

#endif