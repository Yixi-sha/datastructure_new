#ifndef SMARTPOINT_CPP
#define SMARTPOINT_CPP

#include "../inc/smartpointer.h"

namespace yixi {

template<typename T>
SmartPointer<T>::SmartPointer(T* p) : pointer<T>(p)
{

}

template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& obj)
{
    this->i_pointer = obj.i_pointer;
    const_cast<SmartPointer<T>&>(obj).i_pointer = nullptr;
}

template<typename T>
SmartPointer<T>& SmartPointer<T>::operator =(SmartPointer<T>& obj)

{
    if(this != &obj)
    {
        T* temp = this->i_pointer;
        this->i_pointer = obj.i_pointer;
        const_cast<SmartPointer<T>&>(obj).i_pointer = nullptr;
        delete temp;
    }

    return *this;

}

template<typename T>
void SmartPointer<T>::clear()
{
    T* temp = this->pointer;
    this->pointer = nullptr;
    delete temp;
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
    if(this->i_pointer != nullptr)
    {
        delete this->i_pointer;
    }
}

#endif // SMARTPOINT_CPP

}
