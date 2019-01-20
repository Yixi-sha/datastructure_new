#ifndef SEQLIST_CPP
#define SEQLIST_CPP

#include "../inc/seqlist.h"
#include "../inc/exception.h"

namespace yixi {

template <typename T>
bool SeqList<T>::insert(int pos,const T& obj)
{
    bool ret = (pos >= 0) && (pos <= i_length);
    ret = ret && ((i_length + 1) <= this->size() );
    if(ret)
    {
        for(int i = i_length - 1 ; i >=  pos ; i--)
        {
            i_mem[i+1] = i_mem[i];
        }
        i_mem[pos] = obj;
        i_length ++;
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"the paramenter is error");
    }
    return ret;
}


template <typename T>
bool SeqList<T>::insert(const T& obj)
{
    return insert(i_length, obj);
}

template <typename T>
bool SeqList<T>::remove(int pos)
{
    bool ret = (pos >=0 ) && (pos < i_length);
    if(ret)
    {
        T temp = i_mem[pos];
        for(int i = pos; i < i_length - 1; i++)
        {
            i_mem[i] = i_mem[i + 1];
        }
        (void)temp;
        i_length--;
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"the paramenter is error");
    }
    return ret;
}

template <typename T>
bool SeqList<T>::set(int pos,const T& obj)
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        i_mem[pos] = obj;
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"the paramenter is error");
    }
    return ret;
}

template <typename T>
bool SeqList<T>::get(int pos, T& obj) const
{
    bool ret = (pos >= 0) && (pos < i_length);

    if(ret)
    {
        obj = i_mem[pos];
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"the paramenter is error");
    }
    return ret;
}

template <typename T>
T& SeqList<T>::get(int pos)
{
    if((pos >= 0) && (pos < i_length))
    {
        return i_mem[pos];
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException,"the paramenter is error");
    }
}

template <typename T>
T SeqList<T>::get(int pos) const
{
    return const_cast<SeqList<T>&>(*this).get(pos);
}

template <typename T>
T SeqList<T>::operator [](int pos) const
{
    return this->get(pos);
}

template <typename T>
T& SeqList<T>::operator [](int pos)
{
    return this->get(pos);
}

template <typename T>
int SeqList<T>::length() const
{
    return i_length;
}

template <typename T>
void SeqList<T>::clear()
{
    int length = i_length;
    for(int i = 0; i < length; i++)
    {
        remove(i_length - 1);
    }
}

template <typename T>
bool SeqList<T>::append(const T& obj)
{
    return insert(obj);
}

template <typename T>
bool SeqList<T>::extend(const List<T>& obj)
{
    bool ret = true;


    for(int i = 0 ; (i < obj.length() )&& ret ; i++)
    {
        ret = insert(obj[i]);
    }


    return ret;
}

template <typename T>
int SeqList<T>::index( const T& obj, const int from) const
{
    int ret = -1;
    for(int i = from; i < this->i_length; i++)
    {
        if(i_mem[i] == obj)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

}

#endif // SEQLIST_CPP
