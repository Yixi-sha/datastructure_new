#ifndef DYNAMICARRAY_CPP
#define DYNAMICARRAY_CPP

#include "../inc/dynamicarray.h"

namespace yixi {

template <typename T>
void DynamicArray<T>::memCopy(T* dis, T* src, int N)
{
    for(int i = 0; i < N ; i++)
    {
        dis[i] = src[i];
    }
}

template <typename T>
void DynamicArray<T>::update(T* newMem, int newSize)
{
    T* origin = this->i_mem;
    this->i_mem = newMem;
    i_size = newSize;
    if(origin != nullptr)
        delete[] origin;
}


template <typename T>
DynamicArray<T>::DynamicArray(int size ) :
i_size(size)
{
    if(0 != size)
    {
        this->i_mem = (new T[size]);
        if(this->i_mem == nullptr)
        {
            i_size = 0;
            THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create DynamicArray");
        }
    }
    else
    {
        this->i_mem = nullptr;
    }

}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& obj) :
i_size(obj.size())
{
    if(0 != obj.size())
    {
        T* temp = (new char[obj.size()]);
        if(temp != nullptr)
        {
            memCopy(temp, obj.i_mem, obj.size());
            this->i_mem = temp;
        }
        else
        {
            i_size = 0;
            THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create DynamicArray");
        }
    }
    else
    {
        this->i_mem = nullptr;
    }

}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator =(const DynamicArray<T>& obj)
{
    if(this != &obj)
    {
        if(0 != obj.size())
        {
            T *temp =(new T[obj.size()]);
            if(temp != nullptr)
            {
                memCopy(temp, obj.i_mem, obj.size());
                update(temp, obj.size());
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to copy DynamicArray");
            }
        }
        else
        {
            this->i_size = 0;
            if(this->i_mem != nullptr)
            {
                T* temp = this->i_mem;
                this->i_mem = nullptr;
                delete[] temp;

            }

        }

    }

    return *this;
}

template <typename T>
int DynamicArray<T>::size() const
{
    return i_size;
}


template <typename T>
bool DynamicArray<T>::reSize(int size)
{
    bool ret = true;

    if(size != i_size)
    {
        if(0 != size)
        {
            T* temp = (new T[size]);
            if(temp != nullptr)
            {
                int tempSize = i_size < size ? i_size : size;
                memCopy(temp, this->i_mem, tempSize);
                update(temp, size);
            }
            else
            {
                ret = false;
                THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to resize DynamicArray");
            }
        }
        else
        {
            this->i_size = 0;
            if(this->i_mem != nullptr)
            {
                T* temp = this->i_mem;
                this->i_mem = nullptr;
                delete[] temp;

            }
        }

    }

    return ret;
}


template <typename T>
DynamicArray<T>::~DynamicArray()
{
    if(this->i_mem != nullptr)
    {
        T* temp = this->i_mem;
        this->i_mem = nullptr;
        delete[] temp;
    }
}


}



#endif // DYNAMICARRAY_CPP
