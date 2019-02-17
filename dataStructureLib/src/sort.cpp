#ifndef SORT_CPP
#define SORT_CPP

#include "../inc/sort.h"

namespace yixi {

template <typename T>
void Sort::swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
void Sort::select(T* obj, int len, bool minToMax)
{
    for(int i = 0; i < len; i++)
    {
        int pos = i;
        int j = i + 1;
        while(j < len)
        {
            if(minToMax ? obj[j] < obj[pos] : obj[j] > obj[pos])
            {
                pos = j;
            }
            j++;
        }
        if(i != pos)
        {
            swap(obj[i], obj[pos]);
        }
    }
}

template <typename T>
void Sort::select(Array<T>& obj, bool minToMax)
{
    select(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort::insert(T* obj, int len, bool minToMax)
{
    for(int i= 1; i < len; i++)
    {
        T temp = obj[i];
        int j = i - 1;
        for( ; j >= 0 ; j--)
        {
            if(minToMax ? obj[j] > temp : obj[j] < temp)
            {
                obj[j + 1] = obj[j];
            }
            else
            {
                break;
            }
        }
        if(j != (i -1))
        {
            obj[j + 1] = temp;
        }
    }
}

template <typename T>
void Sort::insert(Array<T>& obj, bool minToMax)
{
    insert(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort::bubble(T* obj, int len, bool minToMax)
{
    bool exchange = true;

    for(int i = 0; i < len && exchange; i++)
    {
        exchange = false;
        for(int j = len - 1; j > i; j--)
        {
            if(minToMax ? obj[j] < obj[j - 1] : obj[j] > obj[j - 1])
            {
                swap(obj[j], obj[j - 1]);
                exchange = true;
            }
        }
    }
}

template <typename T>
void Sort::bubble(Array<T>& obj, bool minToMax)
{
    bubble(obj.address(), obj.size(), minToMax);
}


template <typename T>
void Sort::shell_select(T* obj, int len, bool minToMax )
{
    int d = len;

    do
    {
        d = d / 3 + 1;

        for(int i = d - 1; i < len ; i += d)
        {
            int pos = i;
            int j = i + d;
            while(j < len)
            {
                if(minToMax ? obj[j] < obj[pos] : obj[j] > obj[pos])
                {
                    pos = j;
                }
                j += d;
            }
            if(i != pos)
            {
                swap(obj[i], obj[pos]);
            }
        }

    }while(d > 1);
}

template <typename T>
void Sort::shell_select(Array<T>& obj, bool minToMax)
{
    shell_select(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort::shell_bubble(T* obj, int len, bool minToMax)
{
    int d = len;
    bool exchange = true;
    do
    {
        d = d / 3 + 1;
        exchange = true;
        for(int i = d - 1; i < len && exchange; i += d)
        {
            exchange = false;
            for(int j = len - d ; j > i; j -= d)
            {
                if(minToMax ? obj[j] < obj[j - d] : obj[j] > obj[j - d])
                {
                    swap(obj[j], obj[j - d]);
                    exchange = true;
                }
            }
        }

    }while(d > 1);
}

template <typename T>
void Sort::shell_bubble(Array<T>& obj, bool minToMax)
{
    shell_bubble(obj.address(), obj.size(), minToMax);
}

}

#endif // SORT_CPP
