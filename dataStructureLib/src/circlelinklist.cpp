#ifndef CIRCLELINKLIST_CPP
#define CIRCLELINKLIST_CPP

#include "../inc/circlelinklist.h"

namespace yixi {


#define Node typename LinkList<T>::Node

template <typename T>
int CricleLinkLlist<T>::mod(int i) const
{
    return (this->i_length == 0) ? 0 : (i % this->i_length);
}

template <typename T>
void CricleLinkLlist<T>::lastToHead(void)
{
    if(this->i_length > 1)
        this->getPre(this->i_length)->next = this->head;
    else if(this->i_length == 1)
        this->head->next  = this->head;
}

template <typename T>
CricleLinkLlist<T>::CricleLinkLlist():
    LinkList<T>::LinkList()
{

}

template <typename T>
CricleLinkLlist<T>::CricleLinkLlist(const T& obj ) :
    LinkList<T>::LinkList(obj)
{
    lastToHead();
}

template <typename T>
CricleLinkLlist<T>::CricleLinkLlist(const CricleLinkLlist<T>& obj) :
    LinkList<T>::LinkList(obj)
{
    lastToHead();
}

template <typename T>
CricleLinkLlist<T>& CricleLinkLlist<T>::operator = (const CricleLinkLlist<T>& obj)
{
    if(this != &obj)
    {
        LinkList<T>::operator =(obj);
        lastToHead();
    }

    return *this;
}


template <typename T>
bool CricleLinkLlist<T>::insert(const T& obj)
{
    return insert(this->i_length, obj);
}

template <typename T>
bool CricleLinkLlist<T>::insert(int pos, const T& obj)
{
    pos = (this->i_length == 0) ? 0 : (pos % (this->i_length + 1));

    bool ret = LinkList<T>::insert(pos, obj);

    if(ret && (0 == pos))
        lastToHead();
    return ret;

}

template <typename T>
bool CricleLinkLlist<T>::remove(int pos)
{
    pos = mod(pos);
    bool ret = (pos >= 0) && (pos < this->i_length);

    if(ret)
    {
        if(0 != pos)
        {
            ret = LinkList<T>::remove(pos);
        }
        else
        {
            Node* temp = this->head;
            if(1 == this->i_length)
            {
                this->head = nullptr;
                this->i_length = 0;
                this->position = nullptr;
            }
            else
            {
                this->head = temp->next;
                this->i_length--;
                if(this->position == temp)
                {
                    this->position = this->position->next;
                }
                lastToHead();
            }
            if(temp != nullptr)
            {
                T temp_T = *reinterpret_cast<T*>(temp->value);
                (void)temp_T;
                delete temp;
            }
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(InvalidParameterException,"Invalid Parameter  in CricleLinkLlist<T>::remove");
    }

    return ret;
}

template <typename T>
bool CricleLinkLlist<T>::set(int pos, const T& obj)
{
    pos = mod(pos);
    return LinkList<T>::set(pos, obj);
}


template <typename T>
T& CricleLinkLlist<T>::get(int pos)
{
    pos = mod(pos);
    return LinkList<T>::get(pos);
}

template <typename T>
bool CricleLinkLlist<T>::get(int pos, T& obj) const
{
    return LinkList<T>::get(mod(pos), obj);
}

template <typename T>
bool CricleLinkLlist<T>::moveTo(int pos)
{
    pos = mod(pos);
    return LinkList<T>::moveTo(pos);
}

template <typename T>
bool CricleLinkLlist<T>::end()
{
    return (this->position == nullptr) || (this->i_length == 0);
}

template <typename T>
void CricleLinkLlist<T>::clear()
{
    while(this->i_length > 1)
        remove(1);
    remove(0);
}

template <typename T>
CricleLinkLlist<T>::~CricleLinkLlist()
{
    this->clear();
}

}


#endif // CIRCLELINKLIST_CPP
