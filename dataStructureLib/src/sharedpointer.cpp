#ifndef SHAREDPOINTER_CPP
#define SHAREDPOINTER_CPP

#include "../inc/sharedpointer.h"

namespace yixi {

template <typename T>
void SharedPointer<T>::init(const SharedPointer<T>& obj)
{
    i_count = obj.i_count;
    if(i_count != nullptr)
    {
        (*i_count)++;
        this->i_pointer = obj.i_pointer;
    }
    else
    {
        this->i_pointer = nullptr;
        THROW_EXCEPTION(NoEnoughMemoryException,"No Enough Memory to create count flag");
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(T* p )
{
    i_count = new int;
    if(i_count != nullptr)
    {
        (*i_count) = 0;
        this->i_pointer = p;
    }
    else
    {
        i_count = nullptr;
        this->i_pointer = p;
        THROW_EXCEPTION(NoEnoughMemoryException,"No Enough Memory to create count flag");
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& obj) : pointer<T>(obj.i_pointer)
{
    this->init(obj);
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator = (const SharedPointer<T>& obj)
{
    if(this != &obj)
    {
        this->clear();
        init(obj);
    }

    return *this;
}

template <typename T>
bool SharedPointer<T>::operator ==(const SharedPointer<T>& obj) const
{
    return this->i_pointer == obj.i_pointer;
}

template <typename T>
bool SharedPointer<T>::operator !=(const SharedPointer<T>& obj) const
{
    return this->i_pointer != obj.i_pointer;
}

template <typename T>
void SharedPointer<T>::clear()
{
    int* temp_count = i_count;
    T* temp_pointer = this->i_pointer;
    i_count = nullptr;
    this->i_pointer = nullptr;

    if(temp_count != nullptr)
    {
        if(0 == (*temp_count))
        {
            delete temp_count;
            delete temp_pointer;
        }
        else
        {
            (*temp_count)--;
        }
    }
    else
    {
        if(temp_pointer != nullptr)
            delete temp_pointer;
    }
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    this->clear();
}

}

#endif // SHAREDPOINTER_CPP
