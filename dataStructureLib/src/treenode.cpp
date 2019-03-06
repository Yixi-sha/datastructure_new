#ifndef TREENODE_CPP
#define TREENODE_CPP

#include "../inc/treenode.h"

namespace yixi
{

template <typename T>
void* TreeNode<T>::operator new(bitsize size) throw()
{
    return Object::operator new(size);
}

template <typename T>
TreeNode<T>::TreeNode(TreeNode<T>* m_parent)
{
    this->m_flag = false;
    parent = m_parent;
}

template <typename T>
bool TreeNode<T>::flag()
{
    return this->m_flag;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
}

}

#endif // TREENODE_CPP
