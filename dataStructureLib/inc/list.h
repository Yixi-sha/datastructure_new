#ifndef LIST_H
#define LIST_H

#include "object.h"

namespace yixi {

template <typename T>
class List : public Object
{
public:
    virtual bool insert(const T& obj) = 0;
    virtual bool insert(int pos, const T& obj) = 0;
    virtual bool remove(int pos) = 0;
    virtual bool set(int pos, const T& obj) = 0;
    virtual bool get(int pos, T& obj) const = 0;
    virtual T& get(int pos) = 0;
    virtual T get(int pos) const = 0;
    virtual T operator [](int pos) const = 0;
    virtual T& operator [](int pos) = 0;
    virtual int length() const = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual bool append(const T& obj) = 0;
    virtual bool extend(const List<T>& obj) = 0;
    virtual int index( const T& obj, const int from = 0) const = 0;
};

}

#endif // LIST_H
