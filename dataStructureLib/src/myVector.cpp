#ifndef _MY_VECTOR_CPP__
#define _MY_VECTOR_CPP__


#include "../inc/myVector.h"
#include "../inc/exception.h"
#include "cstring"

#include <iostream>

using namespace std;

namespace yixi{

template<typename T>
MyVector<T>::MyVector():element(nullptr), firstFree(nullptr), cap(nullptr) {

}

template<typename T>
int MyVector<T>::size() const{
    return firstFree - element;
}

template<typename T>
int MyVector<T>::capacity() const{
    return cap - element;
}

template<typename T>
void MyVector<T>::reallocate(){
    int m_size = cap - element;
    bool zeroFlag = false;
    if(m_size == 0){
        m_size = 1;
        zeroFlag = true;
    }
    char* tmpPtr = new char[sizeof(T) * m_size * 2];
    T* m_element = reinterpret_cast<T*>(tmpPtr);
    if(m_element == nullptr){
        THROW_EXCEPTION(NoEnoughMemoryException, "NoEnoughMemoryException in reallocate\n");
    }
    
    if(zeroFlag){
        firstFree = m_element;
    }else{
        memcpy(m_element, element, m_size * sizeof(T));
        firstFree = m_element + m_size;
    }
    cap = m_element + m_size * 2;
    

    

    char* m_willFree = reinterpret_cast<char*>(element);
    element = m_element;
    delete[] m_willFree;
}

template<typename T>
void MyVector<T>::check_n_alloc(){
    if(firstFree == cap)
        reallocate();  
}

template<typename T>
void MyVector<T>::push_back(const T& obj){
    check_n_alloc();
    new(firstFree++) T(obj);
}

template<typename T>
MyVector<T>::~MyVector(){
   
    int m_size = size();
    cout << size() << endl;
    cout << capacity() << endl;
    cout << element << "\t" << firstFree << "\t" << cap << "\t" <<endl;
    for(int i = 0; i < capacity(); ++i)
        cout << element[i].i << endl;
    for(int i = 0; i < m_size; ++i)
        element[i].~T();
    char* m_willFree = reinterpret_cast<char*>(element);
    delete[] m_willFree;

}

}

#endif 