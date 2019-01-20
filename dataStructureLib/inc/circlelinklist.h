#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H

#include "linklist.h"

namespace yixi {

template <typename T>

class CricleLinkLlist : public LinkList<T>
{
protected:
    void lastToHead(void);
    int mod(int i) const;

public:
    CricleLinkLlist();
    CricleLinkLlist(const T& obj );
    CricleLinkLlist(const CricleLinkLlist<T>& obj);

    CricleLinkLlist<T>& operator = (const CricleLinkLlist<T>& obj);



    virtual bool insert(const T& obj);
    virtual bool insert(int pos, const T& obj);
    virtual bool remove(int pos);
    virtual bool set(int pos, const T& obj);
    virtual bool get(int pos, T& obj) const;
    virtual T& get(int pos);
    virtual void clear();




    virtual bool moveTo(int pos);
    virtual bool end();

    ~CricleLinkLlist();
};

}


#include "../src/circlelinklist.cpp"
#endif // CIRCLELINKLIST_H
