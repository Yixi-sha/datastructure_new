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

}

#endif // SORT_CPP
