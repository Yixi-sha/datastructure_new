#ifndef _MY_VECTOR_H__
#define _MY_VECTOR_H__

namespace yixi{

template<typename T>

class MyVector{
private:
    T* element;
    T* firstFree;
    T* cap;

    //void alloc_n_copy(int n, T* begin, T* end);
    //void free(T* addr);
    void check_n_alloc(); // if do not have suffient room, it will alloc
    void reallocate();

public:
    MyVector();
    MyVector(const MyVector& obj);

    //MyVector& operator = (const MyVector& obj);

    ~MyVector();

    void push_back(const T& obj);
    int size() const;
    int capacity() const;
    //T* begin();
    //T* end();
};

}

#include "../src/myVector.cpp"

#endif