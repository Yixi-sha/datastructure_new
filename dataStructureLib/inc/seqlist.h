#ifndef SEQLIST_H
#define SEQLIST_H

#include "list.h"

namespace yixi {

template <typename T>
class SeqList : public List<T>
{

protected:
    T* i_mem;
    int i_length;

public:
    virtual bool insert(const T& obj);
    virtual bool insert(int pos,const T& obj);
    virtual bool remove(int pos) ;
    virtual bool set(int pos, const T& obj);
    virtual bool get(int pos, T& obj) const;
    virtual T& get(int pos);
    virtual T get(int pos) const;
    virtual T operator [](int pos) const;
    virtual T& operator [](int pos);
    virtual int length() const;
    virtual int size() const = 0;
    virtual void clear();
    virtual bool append(const T& obj);
    virtual bool extend(const List<T>& obj);
    virtual int index( const T& obj, const int from = 0) const;
};


}

#include "../src/seqlist.cpp"
#endif // SEQLIST_H
