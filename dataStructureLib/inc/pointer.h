#ifndef POINTER_H
#define POINTER_H

#include "object.h"
#include "exception.h"

namespace yixi {

template <typename T>
class pointer : public Object
{
protected:
    T* i_pointer;
public:
    pointer(T* p = nullptr);

    T& operator*(void) const ;
    T& operator * (void) ;
    T* operator -> (void) ;

    const T* operator -> (void) const;

    bool isNull(void) const;
    T* get() const ;
};


}





#include "../src/pointer.cpp"

#endif // POINTER_H
