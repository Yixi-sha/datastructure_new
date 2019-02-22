#ifndef SORT_H
#define SORT_H

#include "object.h"
#include "array.h"

namespace yixi {

template <typename T>
class Sort : public Object
{
private:
    Sort();
    Sort(const Sort<T>& obj);

    Sort& operator =(const Sort<T>& obj);


    static void swap(T& a, T& b);

//    template <typename T>
    static void merge_quick_two(int start, int end,T* obj, bool minToMax = true);

//    template <typename T>
    static void merge(int start, int end, T* obj, T* help, bool minToMax = true);

//    template <typename T>
    static void quick(int start, int end, T* obj, bool minToMax = true);

public:
//    template <typename T>
    static void select(T* obj, int len, bool minToMax = true); // don't steady
//    template <typename T>
    static void select(Array<T>& obj, bool minToMax = true);

//    template <typename T>
    static void insert(T* obj, int len, bool minToMax = true); // it is steady
//    template <typename T>
    static void insert(Array<T>& obj, bool minToMax = true);

//    template <typename T>
    static void bubble(T* obj, int len, bool minToMax = true);
//    template <typename T>
    static void bubble(Array<T>& obj, bool minToMax = true);

//    template <typename T>
    static void shell_select(T* obj, int len, bool minToMax = true);
//    template <typename T>
    static void shell_select(Array<T>& obj, bool minToMax = true);

//    template <typename T>
    static void shell_bubble(T* obj, int len, bool minToMax = true);
//    template <typename T>
    static void shell_bubble(Array<T>& obj, bool minToMax = true);

//    template <typename T>
    static void merge(T* obj, int len, bool minToMax = true);
//    template <typename T>
    static void merge(Array<T>& obj, bool minToMax = true);

//    template <typename T>
    static void quick(T* obj, int len, bool minToMax = true);
//    template <typename T>
    static void quick(Array<T>& obj, bool minToMax = true);
};

}



#include "../src/sort.cpp"
#endif // SORT_H
