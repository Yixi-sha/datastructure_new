#ifndef INDEXTREE_CPP
#define INDEXTREE_CPP

#include "../inc/indextree.h"

namespace yixi
{
template <typename T>
IndexTree<T>::IndexTree(ITNode<T>* root)
{
    mroot = root;
}
}

#endif