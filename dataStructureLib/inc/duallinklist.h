#ifndef DUALLINKLIST_H
#define DUALLINKLIST_H

#include "list.h"

namespace yixi {

template <typename T>
class DualLinklist : public List<T>
{
protected:
    struct Node : public Object
    {
        char value[sizeof(T)];
        Node* next;
        Node* pre;
    };

    int i_length;

    Node* i_position;
    Node* i_head;

    Node* getPre(int pos) const;

    Node* create();
    void destroy(Node* obj);
    void copyInit(const DualLinklist<T>& obj);

public:
    DualLinklist();
    DualLinklist(const T& obj );
    DualLinklist(const DualLinklist<T>& obj);

    DualLinklist<T>& operator = (const DualLinklist<T>& obj);

    virtual bool insert(const T& obj);
    virtual bool insert(int pos, const T& obj) ;
    virtual bool remove(int pos) ;
    virtual bool set(int pos, const T& obj) ;
    virtual bool get(int pos, T& obj) const ;
    virtual T& get(int pos) ;
    virtual T get(int pos) const ;
    virtual T operator [](int pos) const ;
    virtual T& operator [](int pos) ;
    virtual int length() const ;
    virtual int size() const ;
    virtual void clear() ;
    virtual bool append(const T& obj) ;
    virtual bool extend(const List<T>& obj) ;
    virtual int index( const T& obj, const int from = 0) const ;

    virtual T& current(void);
    virtual bool next(int step = 1);
    virtual bool moveTo(int pos);
    virtual bool end();

    virtual bool pre(int step = 1);

    ~DualLinklist();
};

}


#include "../src/duallinklist.cpp"

#endif // DUALLINKLIST_H
