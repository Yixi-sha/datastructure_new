#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "seqlist.h"

namespace yixi {

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int i_size;

    void memCopy(T* dis, T* src, int N);
    void update(T* newMem, int newLength, int newSize);
public:
    DynamicList(int N = 0);
    DynamicList(const DynamicList& obj);
    DynamicList<T>& operator = (const DynamicList& obj);
    virtual int size() const;
    bool reSize(int N);
    ~DynamicList();

};



}



#include "../src/dynamiclist.cpp"
#endif // DYNAMICLIST_H
