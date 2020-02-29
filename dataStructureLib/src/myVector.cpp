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
void MyVector<T>::copy_from_other(const MyVector& obj){
    char* nextElementChar = new char[sizeof(T) * obj.capacity()];
    element = reinterpret_cast<T*>(nextElementChar);
    if(element == nullptr)
    THROW_EXCEPTION(NoEnoughMemoryException, "NoEnoughMemoryException in MyVector(const&)\n"); 

    for(int i = 0; i < obj.size(); ++i)
        new(&(element[i])) T(obj[i]);
        
    firstFree = element + obj.size();
    cap = element + obj.capacity();
}

template<typename T>
MyVector<T>::MyVector(const MyVector& obj){
    if(obj.size() != 0){
       copy_from_other(obj); 
    }
    
}

template<typename T>
MyVector<T>& MyVector<T>::operator = (const MyVector& obj){
    if(this != &obj){
        T* freeAddr = element;
        int freeSize = size();
        if(0 != obj.size())
            copy_from_other(obj);
        else{
            element = nullptr;
            cap = nullptr;
            firstFree = nullptr;
        }
        free(freeAddr, freeSize);
    }
    return *this;
}

template<typename T>
T& MyVector<T>::operator [] (int pos){
    if(pos < 0 || pos >= size())
        THROW_EXCEPTION(InvalidParameterException, "InvalidParameterException in T& MyVector<T>::operator [] (int pos)\n");

    return element[pos];
}

template<typename T>
T MyVector<T>::operator [] (int pos) const{
    return const_cast<MyVector<T>&>(*this)[pos];
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
    //do not call free for do not call destructor
    char* m_willFree = reinterpret_cast<char*>(element);
    element = m_element;
    if(m_willFree)
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
void MyVector<T>::free(T* addr, int size){
    for(int i = size - 1; i >= 0; --i)
        addr[i].~T();
    char* m_willFree = reinterpret_cast<char*>(addr);
    if(addr)
        delete[] m_willFree;
}

template<typename T>
MyVector<T>::~MyVector(){
    free(element, size());
}

template<typename T>
T* MyVector<T>::begin(){
    return element;
}

template<typename T>
T* MyVector<T>::end(){
    return firstFree;
}

}

#endif 