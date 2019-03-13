#ifndef STATICSTACK_H
#define STATICSTACK_H

#include "stack.h"

namespace yixi
{

template <typename T, int N>
class StaticStack : public Stack<T>
{
protected:
    char m_space[sizeof(T)*N];
    int m_top;
    int m_size;

public:
    StaticStack();
    int size() const ;
    virtual void push(const T& e);
    virtual T pop();
    virtual T& top();
    virtual void clear();
    virtual int length();
    virtual bool isEmtry();
};

} // yixi

#include "../src/staticstack.cpp"

#endif // STATICSTACK_H