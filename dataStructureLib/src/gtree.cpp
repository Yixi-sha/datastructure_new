#ifndef GTREE_CPP
#define GTREE_CPP

#include "../inc/gtree.h"

namespace yixi
{

template <typename T>
GTree<T>::GTree(const T& obj)
{

}

template <typename T>
GTree<T>::GTree(GTreeNode<T>* obj)
{

}

template <typename T>
bool GTree<T>::insert(TreeNode<T>* node)
{
    bool ret = true;

    return ret;
}

template <typename T>
bool GTree<T>::insert(const T& value, TreeNode<T>* parent)
{
    bool ret = true;

    return ret;
}

template <typename T>
SharedPointer<Tree<T>> GTree<T>::remove(const T& value)
{
    return nullptr;
}

template <typename T>
SharedPointer< Tree<T> > GTree<T>::remove(TreeNode<T>* node)
{
    SharedPointer< Tree<T> > ret;
    return ret;
}

template <typename T>
GTreeNode<T>* GTree<T>::index(const T& value, GTreeNode<T>* root) const
{
    GTreeNode<T>* ret = nullptr;
    if(value == root->value)
    {
        ret = root;
    }
    else
    {
        for(root->child.moveTo(0); !root->child.end() && (ret == nullptr); root->child.next(1))
        {
            ret = index(value, root->child.current());
        }
    }
    
    return ret;
}

template <typename T>
TreeNode<T>* GTree<T>::index(const T& value) const
{
    return index(value, this->m_root);
}

template <typename T>
TreeNode<T>* GTree<T>::index(TreeNode<T>* node) const
{
    GTreeNode<T>* ret = nullptr;
    return ret;
}

template <typename T>
TreeNode<T>* GTree<T>::root() const
{
    return dynamic_cast<GTreeNode<T>* >(this->m_root);
}

template <typename T>
int GTree<T>::degree() const
{
    int ret = 0;
    return ret;
}

template <typename T>
int GTree<T>::count() const
{
    int ret = 0;
    return ret;
}

template <typename T>
int GTree<T>::height() const
{
    int ret = 0;
    return ret;
}

template <typename T>
void GTree<T>::clear()
{

}

template <typename T>
GTree<T>::~GTree()
{
    this->clear();
}

}



#endif // GTREE_CPP
