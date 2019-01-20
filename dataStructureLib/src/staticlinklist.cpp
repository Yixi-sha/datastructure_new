#ifndef STATICLINKLIST_CPP
#define STATICLINKLIST_CPP

#include "../inc/staticlinklist.h"

namespace yixi {


template <typename T, int N>
void StaticLinkList<T, N>::init()
{
    for(int i = 0; i < N; i++)
    {
        i_flage[i] = 0;
    }
}

template <typename T, int N>
StaticLinkList<T, N>::StaticLinkList()
{
    init();
}



template <typename T, int N>
typename LinkList<T>::Node*  StaticLinkList<T, N>::create()
{
    Node* ret = NULL;
    for(int i = 0;i<N;i++)
    {
        if(!i_flage[i])
        {
            ret = reinterpret_cast<Node*>(i_mem) + i;
            i_flage[i] = 1;
            break;
        }
    }
    return ret;
}

template <typename T, int N>
void StaticLinkList<T, N>::destroy(typename LinkList<T>::Node* obj)
{
    int temp = (reinterpret_cast<bitsize>(obj) - reinterpret_cast<bitsize>(i_mem));

    if(temp)
    {
        temp /= sizeof(Node);
    }
    i_flage[temp] = 0;
}


template <typename T, int N>
StaticLinkList<T,N>& StaticLinkList<T, N>::operator = (const StaticLinkList<T,N>& obj)
{
    if(this != &obj)
    {
        this->clear();
        this->copyInit(obj);
    }

    return *this;
}


template <typename T, int N>
int StaticLinkList<T, N>::size() const
{
    return N;
}

template <typename T, int N>
StaticLinkList<T, N>::~StaticLinkList()
{
    this->clear();
}

}


#endif // STATICLINKLIST_CPP
