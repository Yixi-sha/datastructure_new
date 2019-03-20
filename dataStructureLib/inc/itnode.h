#ifndef ITNODE_H
#define ITNODE_H

#include "object.h"
namespace yixi
{
template <typename T>
class ITNode : public Object
{
public:
    T value;
    ITNode<T>* mleft;
    ITNode<T>* mright;
    ITNode();  
};

} // yixi

#include "../src/itnode.cpp"
#endif