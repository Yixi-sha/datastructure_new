#ifndef LINKSTACK_CPP
#define LINKSTACK_CPP

#include "../inc/linkstack.h"
#include "../inc/exception.h"

namespace yixi
{

template <typename T>
void LinkStack<T>::push(const T& e)
{
    m_list.insert(0,e);
}

template <typename T>
T LinkStack<T>::pop()
{
    if(m_list.length() > 0)
    {
        T temp = m_list.get(0);  //lack exception protecting
        m_list.remove(0);
        return temp;
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"Stack  space don`t have element");
    }
}

template <typename T>
T& LinkStack<T>::top()
{
    if(m_list.length() > 0)
    {
        return  m_list.get(0);
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"Stack  space don`t have element");
    }
}

template <typename T>
void LinkStack<T>::clear()
{
    m_list.clear();
}

template <typename T>
int LinkStack<T>::length()
{
    return m_list.length();
}

template <typename T>
bool LinkStack<T>::isEmtry()
{
    return (m_list.length() == 0);
}

} // yixi



#endif