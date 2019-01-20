#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include "linklist.h"

namespace yixi {


template <typename T, int N>
class StaticLinkList : public LinkList<T>
{
protected:
    typedef typename LinkList<T>::Node Node;



    StaticLinkList(const StaticLinkList<T, N>& obj);

    char i_mem[sizeof(Node) * N];
    bool i_flage[N];

    virtual Node* create();

    virtual void destroy(Node* obj);

    virtual void init();


public:
    StaticLinkList();

    StaticLinkList<T,N>& operator = (const StaticLinkList<T,N>& obj);

    virtual int size() const;

    ~StaticLinkList();
};


}





#include "../src/staticlinklist.cpp"

#endif // STATICLINKLIST_H
