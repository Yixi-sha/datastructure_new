#ifndef GTREE_H
#define GTREE_H

#include "tree.h"
#include "gtreenode.h"

namespace yixi
{

template <typename T>
class GTree : public Tree<T>
{
protected:
    virtual GTreeNode<T>* index(const T& value, GTreeNode<T>* root) const ;
public:
    GTree(const T& obj);
    GTree(GTreeNode<T>* obj = nullptr);

    virtual bool insert(TreeNode<T>* node);
    virtual bool insert(const T& value, TreeNode<T>* parent);
    virtual SharedPointer< Tree<T> >remove(const T& value);
    virtual SharedPointer< Tree<T> >remove(TreeNode<T>* node) ;
    virtual TreeNode<T>* index(const T& value) const ;
    virtual TreeNode<T>* index(TreeNode<T>* node) const ;
    virtual TreeNode<T>* root() const ;
    virtual int degree() const ;
    virtual int count() const ;
    virtual int height() const ;
    virtual void clear() ;

    virtual ~GTree();
};

}

#include "../src/gtree.cpp"
#endif // GTREE_H
