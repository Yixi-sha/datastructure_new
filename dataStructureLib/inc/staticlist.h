#ifndef STATICLIST_H
#define STATICLIST_H
#include "seqlist.h"

namespace yixi {

template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
    char i_mem_static[sizeof(T) * N];

public:
    StaticList();
    StaticList(const StaticList& obj);
    StaticList<T,N>& operator = (const StaticList& obj);
    virtual int size() const;
    ~StaticList();

};

}




#include "../src/staticlist.cpp"

#endif // STATICLIST_H
