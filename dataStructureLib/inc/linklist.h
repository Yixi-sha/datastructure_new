#ifndef LINKLIST_H
#define LINKLIST_H

#include "list.h"

namespace yixi {

template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
        char value[sizeof(T)];
        Node* next;
    };

    Node* head;
    int i_length;

    Node* position;

    virtual Node* getPre(int pos) const;

    virtual void copyInit(const LinkList<T>& obj);

    virtual Node* create();
    virtual void destroy(Node* obj);

public:
    LinkList();
    LinkList(const T& obj );
    LinkList(const LinkList<T>& obj);

    LinkList<T>& operator = (const LinkList<T>& obj);



    virtual bool insert(const T& obj);
    virtual bool insert(int pos, const T& obj);
    virtual bool remove(int pos);
    virtual bool set(int pos, const T& obj);
    virtual bool get(int pos, T& obj) const;
    virtual T& get(int pos);
    virtual T get(int pos) const;
    virtual T operator [](int pos) const;
    virtual T& operator [](int pos);
    virtual int length() const;
    virtual int size() const;
    virtual void clear();
    virtual bool append(const T& obj);
    virtual bool extend(const List<T>& obj);

    virtual int index( const T& obj, const int from = 0) const;


    virtual T& current(void);
    virtual bool next(int step = 1);
    virtual bool moveTo(int pos);
    virtual bool end();

    ~LinkList();
};

}

#include "../src/linklist.cpp"

#endif // LINKLIST_H
