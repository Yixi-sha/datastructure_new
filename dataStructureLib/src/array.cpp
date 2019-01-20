#ifndef ARRARY_CPP
#define ARRARY_CPP
#include "../inc/array.h"
#include "../inc/exception.h"

namespace yixi {

template <typename T>
bool Array<T>::set(int pos, const T& obj)
{
    bool ret = (pos >= 0) && (pos < this->size());

    if(ret)
    {
        i_mem[pos] = obj;
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException,"Index Out Of Bounds in Array  set");
    }
    return ret;
}


template <typename T>
bool Array<T>::get(int pos,T& obj) const
{
    bool ret = (pos >= 0) && (pos < this->size());

    if(ret)
    {
        obj = i_mem[pos];
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException,"Index Out Of Bounds in Array  get");
    }
    return ret;
}


template <typename T>
T& Array<T>::get(int pos)
{
    if((pos >= 0) && (pos < this->size()))
    {
        return i_mem[pos];
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException,"Index Out Of Bounds in Array  get");
    }
}

template <typename T>
T Array<T>::get(int pos) const
{
    return const_cast<Array<T>&>(*this).get(pos);
}


template <typename T>
T& Array<T>::operator[](int pos)
{
    return this->get(pos);
}

template <typename T>
T Array<T>::operator [](int pos) const
{
    return this->get(pos);
}

}

#endif // ARRARY_CPP
