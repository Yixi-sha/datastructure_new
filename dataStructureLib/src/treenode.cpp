#ifndef TREENODE_CPP
#define TREENODE_CPP

#include "../inc/treenode.h"

namespace yixi
{

template <typename T>
TreeNode<T>::TreeNode(TreeNode<T>* m_parent)
{
    parent = m_parent;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
}

}

#endif // TREENODE_CPP
