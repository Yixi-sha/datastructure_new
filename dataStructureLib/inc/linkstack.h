#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "stack.h"
#include "linklist.h"

namespace yixi
{

template <typename T>
class LinkStack : public Stack<T>
{
protected:
    LinkList<T> m_list;

public:
    virtual void push(const T& e);
    virtual T pop();
    virtual T& top();
    virtual void clear();
    virtual int length();
    virtual bool isEmtry();
}; 

} // yixi


#include "../src/linkstack.cpp"


#endif