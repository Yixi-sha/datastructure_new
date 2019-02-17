#ifndef SORT_H
#define SORT_H

#include "object.h"
#include "array.h"

namespace yixi {


class Sort : public Object
{
private:
    Sort();
    Sort(const Sort& obj);

    Sort& operator =(const Sort& obj);

    template <typename T>
    static void swap(T& a, T& b);

public:
    template <typename T>
    static void select(T* obj, int len, bool minToMax = true); // don't steady
    template <typename T>
    static void select(Array<T>& obj, bool minToMax = true);

    template <typename T>
    static void insert(T* obj, int len, bool minToMax = true); // it is steady
    template <typename T>
    static void insert(Array<T>& obj, bool minToMax = true);

    template <typename T>
    static void bubble(T* obj, int len, bool minToMax = true);
    template <typename T>
    static void bubble(Array<T>& obj, bool minToMax = true);

    template <typename T>
    static void shell_select(T* obj, int len, bool minToMax = true);
    template <typename T>
    static void shell_select(Array<T>& obj, bool minToMax = true);

    template <typename T>
    static void shell_bubble(T* obj, int len, bool minToMax = true);
    template <typename T>
    static void shell_bubble(Array<T>& obj, bool minToMax = true);

};

}



#include "../src/sort.cpp"
#endif // SORT_H
