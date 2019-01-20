#ifndef SMARTPOINT_H
#define SMARTPOINT_H
#include "pointer.h"



namespace yixi {

template<typename T>
class SmartPointer : public pointer<T>
{
public:
    SmartPointer(T* p = nullptr);
    SmartPointer(const SmartPointer<T>& obj);
    SmartPointer<T>& operator =(SmartPointer<T>& obj);

    void clear();

    ~SmartPointer();

};


}

#include "../src/smartpointer.cpp"
#endif // SMARTPOINT_H
