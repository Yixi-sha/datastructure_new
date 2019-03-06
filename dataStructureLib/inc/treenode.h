#ifndef TREENODE_H
#define TREENODE_H

#include "object.h"

namespace yixi
{
template <typename T>
class TreeNode : public Object
{
protected:
    bool m_flag;
    void* operator new(bitsize size) throw();

    TreeNode(const TreeNode& obj);
    TreeNode<T>& operator = (const TreeNode& obj);

public:
    T value;
    TreeNode<T>* parent;
    TreeNode(TreeNode<T>* m_parent = NULL);
    bool flag();
    virtual ~TreeNode();
};

}

#include "../src/treenode.cpp"
#endif // TREENODE_H
