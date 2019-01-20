#ifndef STATICLIST_CPP
#define STATICLIST_CPP

#include "../inc/staticlist.h"

namespace yixi {

template <typename T, int N>
StaticList<T, N>::StaticList()
{
    this->i_length = 0;
    this->i_mem = reinterpret_cast<T*>(&i_mem_static);
}

template <typename T, int N>
StaticList<T, N>::StaticList(const StaticList& obj)
{
    this->i_mem = reinterpret_cast<T*>(&i_mem_static);

    for(int i = 0;i < N; i++)
    {
        this->i_mem[i] = obj[i];
    }
}

template <typename T, int N>
StaticList<T, N>& StaticList<T, N>::operator = (const StaticList& obj)
{
    if(this != &obj)
    {
        for(int i = 0;i < N; i++)
        {
            this->i_mem[i] = obj[i];
        }
    }
}

template <typename T, int N>
int StaticList<T, N>::size() const
{
    return N;
}


template <typename T, int N>
StaticList<T, N>::~StaticList()
{
    this->clear();
}

}


#endif // STATICLIST_CPP
