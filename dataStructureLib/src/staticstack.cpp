#ifndef STATICSTACK_CPP
#define STATICSTACK_CPP

#include "../inc/staticstack.h"
#include "../inc/exception.h"

namespace yixi
{

template <typename T, int N>
StaticStack<T, N>::StaticStack()
{
    m_size = 0;
    m_top = -1;
} 

template <typename T, int N>
int StaticStack<T, N>::size() const
{
    return N;
}

template <typename T, int N>
void StaticStack<T, N>::push(const T& e)
{

    if(m_size<N)
    {
        reinterpret_cast<T*>(m_space)[m_top+1] = e;
        m_top++;
        m_size++;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"No Enough  space to push new element");
    }
}

template <typename T, int N>
T StaticStack<T, N>::pop()
{
    if(m_size > 0)
    {
        m_top--;
        m_size--;
        return (reinterpret_cast<T*>(m_space)[m_top+1]);
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"Stack  space don`t have element");
    }
}

template <typename T, int N>
T& StaticStack<T, N>::top()
{
    if(m_size > 0)
    {
        return (reinterpret_cast<T*>(m_space)[m_top]);
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"Stack  space don`t have element");
    }
}

template <typename T, int N>
void StaticStack<T, N>::clear()
{
    m_size = 0;
    m_top = -1;
}

template <typename T, int N>
int StaticStack<T, N>::length()
{
    return m_size;
}

template <typename T, int N>
bool StaticStack<T, N>::isEmtry()
{
    return (m_size == 0);
}
}// yixi


#endif