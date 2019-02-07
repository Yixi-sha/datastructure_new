#ifndef DUALLINKLIST_CPP
#define DUALLINKLIST_CPP

#include "../inc/duallinklist.h"
#include "../inc/exception.h"

namespace yixi {

template <typename T>
void DualLinklist<T>::copyInit(const DualLinklist<T>& obj)
{
    i_head = create();

    if(i_head != nullptr)
    {
        i_position = i_head;
        i_position ->pre = nullptr;

        for(; i_length < obj.length() - 1; i_length++ , i_position = i_position->next )
        {
            *(reinterpret_cast<T*>(i_position->value)) = obj[i_length];
            i_position->next = create();
            if(i_position->next == nullptr)
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create create() in copyInit");
                break;
            }
            i_position->next->pre = i_position;
        }

        *(reinterpret_cast<T*>(i_position->value)) = obj[i_length];
        i_length++;
        i_position->next = nullptr;


    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create create() in copyInit");
    }

    i_position = i_head;
}

template <typename T>
DualLinklist<T>::DualLinklist() :
    i_length(0)
{
    i_head = nullptr;
}

template <typename T>
DualLinklist<T>::DualLinklist(const T& obj ) :
    i_length(0)
{
    insert(0, obj);
}

template <typename T>
DualLinklist<T>::DualLinklist(const DualLinklist<T>& obj)
{
    copyInit(obj);
}

template <typename T>
DualLinklist<T>& DualLinklist<T>::operator = (const DualLinklist<T>& obj)
{
    if(this != &obj)
    {
        clear();
        copyInit(obj);
    }

    return *this;
}

template <typename T>
typename DualLinklist<T>::Node* DualLinklist<T>::getPre(int pos) const
{
    Node* ret = i_head;
    for(int i = 0; ( (i < pos - 1) && (ret != nullptr)); i++)
    {
        ret = ret->next;
    }

    return ret;
}

template <typename T>
typename DualLinklist<T>::Node* DualLinklist<T>::create()
{
    return new Node();
}

template <typename T>
void DualLinklist<T>::destroy(typename DualLinklist<T>::Node* obj)
{
    delete obj;
}

template <typename T>
bool  DualLinklist<T>::insert(const T& obj)
{
    return insert(i_length, obj);
}

template <typename T>
bool DualLinklist<T>::insert(int pos, const T& obj)
{
    bool ret = (pos >= 0) && (pos <= i_length);

    if(ret)
    {
        Node* temp = create();

        if(temp != nullptr)
        {
            *reinterpret_cast<T*>(temp->value) = obj;
            if(0 == pos)
            {
                temp->next = i_head;
                temp->pre = nullptr;

                if(i_head != nullptr)
                    i_head->pre = temp;

                i_head =  temp;
            }
            else
            {
                Node* pre = getPre(pos);
                temp->next = pre->next;
                pre->next = temp;

                temp->pre = pre;

                if(temp->next != nullptr)
                    temp->next->pre = temp;
            }

            i_length++;
        }
        else
        {
            ret = false;
            THROW_EXCEPTION(NoEnoughMemoryException,"No Enough Memory to create new node in DualLinklist<T>::insert");
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(InvalidParameterException, " Invalid Parameter in DualLinklist<T>::insert");
    }

    return ret;
}

template <typename T>
bool DualLinklist<T>::remove(int pos)
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        if(0 != pos)
        {
            Node* pre = getPre(pos);
            Node* temp = pre->next;
            pre->next = temp->next;

            if(temp->next != nullptr)
                temp->next->pre = pre;

            i_length--;
            T target = *(reinterpret_cast<T*>(temp->value));
            (void)target;

            if(temp == i_position)
                i_position = i_position->next;

            destroy(temp);
        }
        else
        {
            Node* temp = i_head;
            i_head = temp->next;

            if(temp->next != nullptr)
                temp->next->pre = nullptr;

            i_length--;
            T target = *(reinterpret_cast<T*>(temp->value));
            (void)target;
            if(temp == i_position)
                i_position = i_position->next;
            destroy(temp);
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(InvalidParameterException, " Invalid Parameter in DualLinklist<T>::remove");
    }

    return ret;
}


template <typename T>
bool DualLinklist<T>::set(int pos, const T& obj)
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        if(0 != pos)
        {
            *reinterpret_cast<T*>(getPre(pos + 1)->value) = obj;
        }
        else
        {
            *reinterpret_cast<T*>(i_head->value) = obj;
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(InvalidParameterException, " Invalid Parameter in DualLinklist<T>::set");
    }

    return ret;
}

template <typename T>
bool DualLinklist<T>::get(int pos, T& obj) const
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        if(0 != pos)
        {
            obj = *reinterpret_cast<T*>(getPre(pos + 1)->value) ;
        }
        else
        {
            obj = *reinterpret_cast<T*>(i_head->value);
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(InvalidParameterException, " Invalid Parameter in DualLinklist<T>::get");
    }

    return ret;
}

template <typename T>
T& DualLinklist<T>::get(int pos)
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        return (*reinterpret_cast<T*>(getPre(pos + 1)->value));
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException, " Invalid Parameter in DualLinklist<T>::get");
    }
}

template <typename T>
T DualLinklist<T>::get(int pos) const
{
    return const_cast<DualLinklist<T>&>(*this).get(pos);
}

template <typename T>
T DualLinklist<T>::operator [](int pos) const
{
    return get(pos);
}

template <typename T>
T& DualLinklist<T>::operator [](int pos)
{
    return get(pos);
}

template <typename T>
int DualLinklist<T>::length() const
{
    return i_length;
}

template <typename T>
int DualLinklist<T>::size() const
{
    return i_length;
}

template <typename T>
void  DualLinklist<T>::clear()
{
    while (i_length)
    {
        remove(0);
    }
}

template <typename T>
bool DualLinklist<T>::append(const T& obj)
{
    return insert(i_length, obj);
}

template <typename T>
bool DualLinklist<T>::extend(const List<T>& obj)
{
    bool ret = true;

    for(int i = 0; i < obj.length() && ret; i++)
    {
        ret = insert(i_length, obj[i]);
    }

    return ret;
}

template <typename T>
int DualLinklist<T>::index( const T& obj, const int from ) const
{
    int ret = -1;
    Node* temp = i_head;
    for(int i = from; i < i_length; i++)
    {
        if(*(reinterpret_cast<T*>(temp->value)) == obj)
        {
            ret = i;
            break;
        }
        temp = temp->next;
    }

    return ret;
}

template <typename T>
T& DualLinklist<T>::current(void)
{
    if(i_position != nullptr)
        return (*(reinterpret_cast<T*>(i_position->value)));
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in current of LinkList");
    }
}

template <typename T>
bool DualLinklist<T>::next(int step)
{
    int ret = (0 != i_length);

    if(ret)
    {
        if(i_position == nullptr)
            i_position = i_head;

        for(int i = 0; i < step;i++)
        {
            i_position = i_position->next;
            if( i_position == nullptr )
            {
                ret = false;
                break;
            }
        }
    }
    else
    {
        THROW_EXCEPTION(InvalidOperationException,"Invalid Operation in next of linlist ");
    }

    return ret;
}

template <typename T>
bool DualLinklist<T>::pre(int step)
{
    int ret = (0 != i_length);

    if(ret)
    {
        if(i_position == nullptr)
            i_position = i_head;

        for(int i = 0; i < step;i++)
        {
            i_position = i_position->pre;
            if( i_position == nullptr )
            {
                ret = false;
                break;
            }
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(InvalidOperationException,"Invalid Operation in next of linlist ");
    }

    return ret;
}

template <typename T>
bool DualLinklist<T>::moveTo(int pos)
{
    bool ret = (pos >= 0) && (pos < i_length);
    if(ret)
    {
        i_position = getPre(pos + 1);
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in moveTo of LinkList");
    }
    return ret;
}



template <typename T>
bool DualLinklist<T>::end()
{
    return i_position == nullptr;
}


template <typename T>
DualLinklist<T>::~DualLinklist()
{
    clear();
}

}


#endif // DUALLINKLIST_CPP
