#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

#include "pointer.h"


namespace yixi {

template <typename T>
class SharedPointer : public pointer<T>
{
protected:
    int* i_count;

    void init(const SharedPointer<T>& obj);
public:
    SharedPointer(T* p = nullptr );
    SharedPointer(const SharedPointer<T>& obj);

    SharedPointer<T>& operator = (const SharedPointer<T>& obj);

    bool operator ==(const SharedPointer<T>& obj) const ;
    bool operator !=(const SharedPointer<T>& obj) const;

    void clear();
    ~SharedPointer();
};

}



#include "../src/sharedpointer.cpp"
#endif // SHAREDPOINTER_H
