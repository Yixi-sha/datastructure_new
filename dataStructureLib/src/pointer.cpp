#ifndef POINTER_CPP
#define POINTER_CPP

#include "../inc/pointer.h"

namespace yixi {

template<typename T>
pointer<T>::pointer(T* p)
{
    i_pointer = p;
}


template<typename T>
T* pointer<T>::operator ->()
{
    return i_pointer;
}

template<typename T>
T& pointer<T>::operator * ()
{
    return *i_pointer;
}

template<typename T>
bool pointer<T>::isNull() const
{
    return (i_pointer == nullptr);
}

template<typename T>
T pointer<T>::operator*(void) const
{
    return *i_pointer;
}

template<typename T>
const T* pointer<T>::operator ->() const
{
    return i_pointer;
}



template<typename T>
T* pointer<T>::get() const
{
    return i_pointer;
}

}



#endif // POINTER_CPP
