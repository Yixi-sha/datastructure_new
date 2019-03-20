#ifndef INDEXTREE_H
#define INDEXTREE_H

#include "object.h"
#include "itnode.h"
#include "linklist.h"

namespace yixi
{

template <typename T>
class IndexTree : public Object
{
protected:
    ITNode<T>* mroot;

public:
    IndexTree(ITNode<T>* root = nullptr);
    virtual bool insert(ITNode<T>* obj) = 0;
    virtual void getLinkList(LinkList<T>* obj) = 0;
};

} // yixi

#include "../src/indextree.cpp"

#endif