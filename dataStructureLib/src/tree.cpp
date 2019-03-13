#ifndef TREE_CPP
#define TREE_CPP

#include "../inc/exception.h"
#include "../inc/tree.h"
namespace yixi
{

template <typename T>
Tree<T>::Tree(TreeNode<T> *obj)
{
    m_root = obj;
}

template <typename T>
Tree<T>::Tree(const T& obj)
{
    TreeNode<T>* tmp = new TreeNode<T>();
    if(tmp != nullptr)
    {
        static_cast<T>(tmp->value) = obj;
        m_root = tmp;
    }
    else
    {
        THROW_EXCEPTION(NoEnoughMemoryException, "No Enough Memory Exception in Tree<T>::Tree");
    }

}

}


#endif // TREE_CPP
