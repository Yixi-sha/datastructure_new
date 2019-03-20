#ifndef AVL_H
#define AVL_H

#include "indextree.h"

namespace yixi
{
template <typename T>
class Avl : public IndexTree<T>
{
protected:
    

    virtual void getLinkList(LinkList<T>* obj, ITNode<T>* root);
    virtual int getDegree(ITNode<T>* root);
    virtual int adjust(ITNode<T>* obj, ITNode<T>* root);
    virtual bool insert(ITNode<T>* obj, ITNode<T>* root);
public:
    virtual bool insert(ITNode<T>* obj);
    virtual void getLinkList(LinkList<T>* obj);
};

}

#include "../src/avl.cpp"

#endif