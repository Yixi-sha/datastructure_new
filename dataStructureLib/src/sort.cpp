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
    int h = 1;
    while(h < len / 3) h = 3 * h + 1;
    while(h >= 1) {
        for(int i = 0; i < len - h; i++) {
            int pos = i;
            for(int j = i + h; (j < len); j += h) 
                if(minToMax ? obj[j] < obj[pos] : obj[pos] > obj[j]) 
                    pos = j;
            if(i != pos)
                swap(obj[pos], obj[i]);
        }
        h = h / 3;             
    }
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
void Sort<T>::shell_insert(T* obj, int len, bool minToMax)
{
    int h = 1;
    while(h < len / 3) h = 3 * h + 1;
    while(h >= 1) {
        for(int i = h; i < len; i++) {
            int pre = i - h;

            for(int j = i; (pre >= 0) && (minToMax ? obj[pre] > obj[j] : obj[pre] < obj[j]); 
            j -= h, pre -= h) {
                swap(obj[j], obj[pre]);
            }
        }
        h = h / 3;
    }
}

template <typename T>
void Sort<T>::shell_insert(Array<T>& obj, bool minToMax)
{
    shell_insert(obj.address(), obj.size(), minToMax);
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
        if((end - start) <= 100) {
            shell_insert(obj + start, end - start + 1, minToMax);
        } else {
            int mid = ((end + start) / 2);
            merge(start, mid, obj, help, minToMax);
            merge(mid + 1, end, obj, help, minToMax);

            int i_start = start, i_mid = mid + 1, pos = start;

            while((i_start <= mid) && (i_mid <= end))
            {
                if(minToMax ? obj[i_start] < obj[i_mid] : obj[i_start] > obj[i_mid])
                {
                    help[pos] = obj[i_start];
                    i_start++;
                }
                else
                {
                    help[pos] = obj[i_mid];
                    i_mid++;
                }
                pos++;
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
void Sort<T>::quick(Array<T>& obj, bool minToMax){
    quick(obj.address(), obj.size(), minToMax);
}

template <typename T>
void Sort<T>::heapCreate(T* obj, int start, int end, bool minToMax){
    int lastNode = (end - start + 1) / 2 - 1 + start;
    while(lastNode >= start){
        int leftNode = lastNode * 2 + 1;
        int rightNode = lastNode * 2 + 2;
        int target = lastNode;

        if(leftNode <= end &&  (minToMax ? obj[leftNode] > obj[target] : obj[leftNode] < obj[target])){
            target = leftNode;
        }

        if(rightNode <= end && (minToMax ? obj[rightNode] > obj[target] : obj[rightNode] < obj[target])){
            target = rightNode;
        }
        
        if(target != lastNode){
            swap(obj[target], obj[lastNode]);
            headAdjust(obj,target, end,minToMax);
        }
        --lastNode;
    }
}

template <typename T>
void Sort<T>::headAdjust(T* obj, int start, int end, bool minToMax){
    int leftNode = start * 2 + 1;
    int rightNode = start * 2 + 2;
    int target = start;   
    if(end > start){
        return;
    }
    if(leftNode <= end &&  (minToMax ? obj[leftNode] > obj[target] : obj[leftNode] < obj[target])){
        target = leftNode;
    }

    if(rightNode <= end && (minToMax ? obj[rightNode] > obj[target] : obj[rightNode] < obj[target])){
        target = rightNode;
    }
        
    if(target != start){
        swap(obj[target], obj[start]);
        headAdjust(obj,target, end,minToMax);
    }

}

template <typename T>
void Sort<T>::heap(T* obj, int len, bool minToMax){
    for(int i = 0; i < len; ++i){
        heapCreate(obj, 0, len - 1 - i, minToMax);
        swap(obj[0], obj[len - 1 - i]);
    }
}

template <typename T>
void Sort<T>::heap(Array<T>& obj, bool minToMax){
    heap(obj.address(), obj.size(), minToMax);
}

template <typename T>
bool Sort<T>::judge(Array<T>& obj, bool minToMax) {
    return judge(obj.address(), obj.size(), minToMax);
}

template <typename T>
bool Sort<T>::judge(T* obj, int len, bool minToMax) {
    for(int i = 1; i < len; i++) {
        if(minToMax ? obj[i] < obj[i - 1] : obj[i] > obj[i - 1])
            return false;
    }
    return true;
}

template <typename T>
void Sort<T>::merge_other(T* obj, int len, bool minToMax ){
    T*  help = reinterpret_cast<T*>(new char[sizeof(T) * len]);
    int i = 1;
    if(help) {
        for(; i < len; i *= 2) {
            for(int j = 0; j < len; j += i * 2) {
                int mid = j + i - 1;
                int end = j + 2 * i - 1;
                end = end < (len - 1) ? end : (len - 1);
                merge_other(j, mid, end, obj, help, minToMax);
            }
        }

        delete[] help;
    }else {
        THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory in merge_other()");
    }
}

template <typename T>
void Sort<T>::merge_other(int start, int mid,int end, T* obj, T* help, bool minToMax ){
    int startCopy = start;
    int endCopy = end;
    int startMid = mid;
    int endMid = startMid + 1;
    int j = start;
    for(; j <= end; j++){
        if(endMid > end)
            help[j] = obj[start++];
        else if(start > startMid)
            help[j] = obj[endMid++];
        else if(minToMax ? obj[start] < obj[endMid] : obj[start] > obj[endMid]) 
            help[j] = obj[start++];
        else 
            help[j] = obj[endMid++];
    }
    j = startCopy;
    while(j <= endCopy) {
        obj[j] = help[j];
        j++;
    }
}

template <typename T>
void Sort<T>::merge_other(Array<T>& obj, bool minToMax) {
    merge_other(obj.address(), obj.size(), minToMax);
}


}

#endif // SORT_CPP
