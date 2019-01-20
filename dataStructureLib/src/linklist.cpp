#ifndef LINKLIST_CPP
#define LINKLIST_CPP

#include "../inc/linklist.h"
#include "../inc/exception.h"

namespace yixi {


template <typename T>
void LinkList<T>::copyInit(const LinkList<T>& obj)
{
    head = create();

    if(head != nullptr)
    {
        position = head;

        for(; i_length < obj.length() - 1; i_length++ , position = position->next)
        {
            *(reinterpret_cast<T*>(position->value)) = obj[i_length];
            position->next = create();

            if(position->next == nullptr)
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create create() in copyInit");
                break;
            }
        }
        *(reinterpret_cast<T*>(position->value)) = obj[i_length];
        i_length++;
        position->next = nullptr;

    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create create() in copyInit");
    }

    position = head;
}

template <typename T>
typename LinkList<T>::Node* LinkList<T>::getPre(int pos) const
{
    Node* ret = head;
    for(int i = 0; ( (i < pos - 1) && (ret != nullptr)); i++)
    {
            ret = ret->next;
    }

    return ret;
}


template <typename T>
typename LinkList<T>::Node* LinkList<T>::create()
{
    return new Node;
}

template <typename T>
void LinkList<T>::destroy(typename LinkList<T>::Node* obj)
{
    delete obj;
}

template <typename T>
LinkList<T>::LinkList() :
i_length(0)
{
    head = nullptr;
    position = nullptr;
}


template <typename T>
LinkList<T>::LinkList(const T& obj ) :
i_length(1)
{
    head = create();
    if(head != nullptr)
    {
        *(reinterpret_cast<T*>(head->value)) = obj;
        position = head;
    }
    else
    {
        position = nullptr;
        THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create create() ");
    }
}

template <typename T>
LinkList<T>::LinkList(const LinkList<T>& obj) :
i_length(0)
{
    copyInit(obj);
}

template <typename T>
LinkList<T>& LinkList<T>::operator = (const LinkList<T>& obj)
{
    if(this != &obj)
    {
        clear();
        i_length = 0;
        copyInit(obj);
    }
    return *this;
}

template <typename T>
bool LinkList<T>::insert(const T& obj)
{
    return insert(i_length, obj);
}

template <typename T>
bool LinkList<T>::insert(int pos, const T& obj)
{
    bool ret = (pos >= 0) && (pos <= i_length);

    if(ret)
    {
        Node* temp = create();
        if(temp != nullptr)
        {
            *(reinterpret_cast<T*>(temp->value)) = obj;
            if(0 != pos)
            {
                Node* pre = getPre(pos);
                temp->next = pre->next;
                pre->next = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
                position = head;
            }
            i_length++;

        }
        else
        {
            ret = false;
            THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory to create create() ");
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in insert of LinkList");
    }

    return ret;


}

template <typename T>
bool LinkList<T>::remove(int pos)
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        if(0 != pos)
        {
            Node* pre = getPre(pos);
            Node* temp = pre->next;

            if(temp == position)
                position = temp->next;

            pre->next = temp->next;
            i_length--;


            T target = *(reinterpret_cast<T*>(temp->value));
            (void)target;
            destroy(temp);
        }
        else
        {
            Node* temp = head;

            if(temp == position)
                position = temp->next;

            head = head->next;
            i_length--;
            T target = *(reinterpret_cast<T*>(temp->value));
            (void)target;
            destroy(temp);


        }

    }
    else
    {
        ret = false;
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in remove of LinkList");
    }

    return ret;
}

template <typename T>
bool LinkList<T>::set(int pos, const T& obj)
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        if(0 != pos)
        {
            *(reinterpret_cast<T*>(getPre(pos)->next->value)) = obj;
        }
        else
        {
            *(reinterpret_cast<T*>(head->value)) = obj;
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in set of LinkList");
    }

    return ret;
}

template <typename T>
bool LinkList<T>::get(int pos, T& obj) const
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        if(0 != pos)
        {
            obj = *(reinterpret_cast<T*>(getPre(pos + 1)->value));
        }
        else
        {
            obj = *(reinterpret_cast<T*>(head->value));
        }
    }
    else
    {
        ret = false;
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in get of LinkList");
    }


    return ret;
}

template <typename T>
T& LinkList<T>::get(int pos)
{
    if((pos >= 0) && (pos < i_length))
    {
        if(0  == pos)
            return *(reinterpret_cast<T*>(this->head->value));

        return *(reinterpret_cast<T*>(getPre(pos + 1)->value));
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in get of LinkList");
    }

}

template <typename T>
T LinkList<T>::get(int pos) const
{
    return (const_cast<LinkList<T>&>(*this)).get(pos);
}

template <typename T>
T LinkList<T>::operator [](int pos) const
{
    return this->get(pos);
}

template <typename T>
T& LinkList<T>::operator [](int pos)
{
    return this->get(pos);
}

template <typename T>
int LinkList<T>::length() const
{
    return i_length;
}

template <typename T>
int LinkList<T>::size() const
{
    return i_length;
}

template <typename T>
void LinkList<T>::clear()
{
    int temp = i_length;
    for(int i = 0; i < temp; i++)
    {
        remove(0);
    }
}

template <typename T>
bool LinkList<T>::append(const T& obj)
{
    return insert(i_length, obj);
}

template <typename T>
bool LinkList<T>::extend(const List<T>& obj)
{
    bool ret = true;

    for(int i = 0; i < obj.length(); i++)
    {
        insert(i_length, obj[i]);
    }

    return ret;
}

template <typename T>
int LinkList<T>::index( const T& obj, const int from ) const
{
    int ret = -1;
    Node* temp = head;
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
T& LinkList<T>::current(void)
{
    if(position != nullptr)
        return (*(reinterpret_cast<T*>(position->value)));
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in current of LinkList");
    }
}

template <typename T>
bool LinkList<T>::next(int step)
{
    int ret = (0 != i_length);

    if(ret)
    {
        if(position == nullptr)
            position = head;

        for(int i = 0; i < step;i++)
        {
            position = position->next;
            if( position == nullptr )
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
bool LinkList<T>::moveTo(int pos)
{
    bool ret = (pos >= 0) && (pos < i_length);
    if(ret)
    {
        position = getPre(pos + 1);
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Index Out Of Bounds Exception in moveTo of LinkList");
    }
    return ret;
}

template <typename T>
bool LinkList<T>::end()
{
    return position == nullptr;
}


template <typename T>
LinkList<T>::~LinkList()
{
    clear();
}

}


#endif // LINKLIST_CPP
