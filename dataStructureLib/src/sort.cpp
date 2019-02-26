#ifndef SORT_CPP
#define SORT_CPP

#include "../inc/sort.h"

namespace yixi {

template <typename T>
void Sort<T>::swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
void Sort<T>::select(T* obj, int len, bool minToMax)
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
void Sort<T>::select(Array<T>& obj, bool minToMax)
{
    select(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort<T>::insert(T* obj, int len, bool minToMax)
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
void Sort<T>::insert(Array<T>& obj, bool minToMax)
{
    insert(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort<T>::bubble(T* obj, int len, bool minToMax)
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
void Sort<T>::bubble(Array<T>& obj, bool minToMax)
{
    bubble(obj.address(), obj.size(), minToMax);
}


template <typename T>
void Sort<T>::shell_select(T* obj, int len, bool minToMax )
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
void Sort<T>::shell_select(Array<T>& obj, bool minToMax)
{
    shell_select(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort<T>::shell_bubble(T* obj, int len, bool minToMax)
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
void Sort<T>::shell_bubble(Array<T>& obj, bool minToMax)
{
    shell_bubble(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort<T>::merge_quick_two(int start, int end, T* obj, bool minToMax)
{
    if(minToMax)
    {
        if(obj[start] > obj[end])
        {
            swap(obj[start], obj[end]);
        }
    }
    else
    {
        if(obj[start] < obj[end])
        {
            swap(obj[start], obj[end]);
        }
    }
}

template <typename T>
void Sort<T>::merge(T* obj, int len, bool minToMax)
{
    T*  help = reinterpret_cast<T*>(new char[sizeof(T) * len]);
    if(help != nullptr)
    {
        merge(0, len - 1, obj, help, minToMax);
        delete[] help;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory for Sort::merge(T* obj, int len, bool minToMax)");
    }
}

template <typename T>
void Sort<T>::merge(int start, int end, T* obj,T* help, bool minToMax)
{
    if(start == end)
    {

    }
    else if(start == (end - 1))
    {
        merge_quick_two(start, end, obj, minToMax);
    }
    else
    {
        int mid = ((end + start) / 2);
        merge(start, mid, obj, help, minToMax);
        merge(mid + 1, end, obj, help, minToMax);

        int i_start = start, i_mid = mid + 1, pos = start;

        while((i_start <= mid) && (i_mid <= end))
        {
            if(minToMax ? obj[i_start] < obj[i_mid] : obj[i_start] > obj[i_mid])
            {
                help[pos] = obj[i_start];
                pos++;
                i_start++;
            }
            else
            {
                help[pos] = obj[i_mid];
                pos++;
                i_mid++;
            }
        }
        while (i_start <= mid)
        {
            help[pos] = obj[i_start];
            pos++;
            i_start++;
        }
        while (i_mid <= end)
        {
            help[pos] = obj[i_mid];
            pos++;
            i_mid++;
        }
        pos = start;
        while(pos <= end)
        {
            obj[pos] = help[pos];
            pos++;
        }
    }
}

template <typename T>
void Sort<T>::merge(Array<T>& obj, bool minToMax)
{
    merge(obj.address(), obj.size(), minToMax);
}


template <typename T>
void Sort<T>::quick(T* obj, int len, bool minToMax)
{
    quick(0, len - 1, obj, minToMax);
}

template <typename T>
void Sort<T>::quick(int start, int end, T obj[], bool minToMax)
{
    if(end == start)
    {

    }
    else if(start == (end - 1))
    {
        merge_quick_two(start, end, obj, minToMax);
    }
    else
    {
        int i_start = start, i_end = end;
        while(i_start < i_end)
        {
            while((i_start < i_end) && (minToMax ? obj[i_start] < obj[i_end] : obj[i_start] > obj[i_end]))
            {
                i_end--;
            }
            if(i_end != i_start)
            {
               swap(obj[i_start], obj[i_end]);
            }
            while((i_start < i_end) && (minToMax ? obj[i_start] <= obj[i_end] : obj[i_start] >= obj[i_end]))
            {
                i_start++;
            }
            if(i_end != i_start)
            {
                swap(obj[i_start], obj[i_end]);
            }

        }
        if(start <= (i_start -1))
            quick(start, i_start - 1, obj, minToMax);
        if((i_start + 1) <= end)
            quick(i_start + 1, end , obj, minToMax);
    }


}

template <typename T>
void Sort<T>::quick(Array<T>& obj, bool minToMax)
{
    quick(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort<T>::createHeap(T* obj, int first, int end, bool minToMax)
{
    int count = end - first + 1;
    obj = obj + first;
    end = count - 1;

    if((count != 0) && ((count % 2) == 0))
    {

        int parent = (end - 1) / 2;
        if(minToMax ? obj[end] < obj[parent] : obj[end] > obj[parent])
        {
            swap(obj[end], obj[parent]);
        }
        end--;
    }
    while (end > 0)
    {
        int parent = (end - 2) / 2;
        if(minToMax ? obj[end] < obj[parent] : obj[end] > obj[parent])
        {
            swap(obj[end], obj[parent]);
        }
        end--;
        if(minToMax ? obj[end] < obj[parent] : obj[end] > obj[parent])
        {
            swap(obj[end], obj[parent]);
        }
        end--;
    }
}

template <typename T>
void Sort<T>::heap(T* obj, int len, bool minToMax )
{
    minToMax = !minToMax;
    len = len - 1;
    for(int i = 0; i < 9;i++)
    {
        Sort<int>::createHeap(obj, i, 9, minToMax);
    }
    for(int i = 0; i <= len; len--)
    {
        createHeap(obj, 0, len, minToMax);
        swap(obj[0], obj[len]);

    }
}

template <typename T>
void Sort<T>::heap(Array<T>& obj, bool minToMax)
{
    heap(obj.address(), obj.size(), minToMax);
}


}

#endif // SORT_CPP
