#ifndef STATICARRAY_CPP
#define STATICARRAY_CPP
#include "../inc/staticarray.h"

namespace yixi {


template <typename T, int N>
StaticArray<T, N>::StaticArray()
{
    this->i_mem = i_memArray;
}


template <typename T, int N>
StaticArray<T, N>::StaticArray(const StaticArray<T, N>& obj)
{
    this->i_mem = i_memArray;
    for(int i = 0; i < N; i++)
    {
        this->i_mem[i] = obj[i];
    }
}

template <typename T, int N>
StaticArray<T,N>& StaticArray<T, N>::operator = (const StaticArray<T, N>& obj)
{
    if(this != &obj)
    {
        this->i_mem = i_memArray;
        for(int i = 0; i < N; i++)
        {
            this->i_mem[i] = obj[i];
        }
    }

    return *this;
}

template <typename T, int N>
int StaticArray<T, N>::size() const
{
    return N;
}



}

#endif // STATICARRAY_CPP
