#ifndef DYNAMICLIST_CPP
#define DYNAMICLIST_CPP

#include "../inc/dynamiclist.h"

namespace yixi {

template <typename T>
void DynamicList<T>::memCopy(T* dis, T* src, int N)
{
    for(int i = 0; i < N ; i++)
    {
        dis[i] = src[i];
    }
}

template <typename T>
void DynamicList<T>::update(T* newMem, int newLength, int newSize)
{
    T* origin = this->i_mem;
    this->i_mem = newMem;
    this->i_length = newLength;
    i_size = newSize;
    if(origin != nullptr)
        delete[] origin;
}

template <typename T>
DynamicList<T>::DynamicList(int N) :
i_size(N)
{
    if(0 != N)
    {
        this->i_mem = reinterpret_cast<T*>(new char[sizeof(T) * N]);
        if(this->i_mem != nullptr)
        {
        }
        else
        {
            i_size = 0;
            THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory to create DynamicList");
        }
    }
    else
    {
        this->i_mem = nullptr;
    }
    this->i_length = 0;


}

template <typename T>
DynamicList<T>::DynamicList(const DynamicList& obj) :
i_size(obj.size())
{
    if(0 != obj.size())
    {
        T* temp = reinterpret_cast<T*>(new char[sizeof(T) * obj.size()]);
        if(temp != nullptr)
        {
            memCopy(temp, obj.i_mem, obj.length());
            this->i_length = obj.length();
            this->i_mem = temp;
        }
        else
        {
            this->i_length = 0;
            this->i_size = 0;
            this->i_mem = nullptr;
            THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory to create DynamicList");
        }
    }
    else
    {
        this->i_length = obj.length();
        this->i_mem = nullptr;
    }

}

template <typename T>
DynamicList<T>& DynamicList<T>::operator = (const DynamicList& obj)
{
    if(this != &obj)
    {
        if(0 != obj.size())
        {
            T* temp = reinterpret_cast<T*>(new char[sizeof(T) * obj.size()]);
            if(temp != nullptr)
            {
                memCopy(temp, obj.i_mem , obj.length());
                update(temp, obj.length(), obj.size());
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory to create DynamicList");
            }
        }
        else
        {
            this->i_size = 0;
            this->i_length = 0;
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
int DynamicList<T>::size() const
{
    return i_size;
}

template <typename T>
bool DynamicList<T>::reSize(int N)
{
    bool ret = true;
    if(N != i_size)
    {
        if(0 != N)
        {
            T* temp = reinterpret_cast<T*>(new char[sizeof(T) * N]);

            if(temp != nullptr)
            {
                int length = this->i_length < N ? this->i_length : N;
                memCopy(temp, this->i_mem , length);
                update(temp, length, N);
            }
            else
            {
                ret = false;
                THROW_EXCEPTION(NoEnoughMemoryException,"No enough memory to create DynamicList");
            }
        }
        else
        {
            this->i_size = 0;
            this->i_length = 0;
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
DynamicList<T>::~DynamicList()
{
    this->clear();
    if(this->i_mem != nullptr)
    {
        T* temp = this->i_mem;
        this->i_mem = nullptr;
        delete[] temp;
    }
}

}


#endif // DYNAMICLIST_CPP
