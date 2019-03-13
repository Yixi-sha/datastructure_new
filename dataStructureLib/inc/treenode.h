#ifndef TREENODE_H
#define TREENODE_H

#include "object.h"

namespace yixi
{
template <typename T>
class TreeNode : public Object
{
public:
    char value[sizeof(T)];
    TreeNode<T>* parent;

    TreeNode(TreeNode<T>* m_parent = nullptr);
    virtual ~TreeNode() = 0;
};

}

#include "../src/treenode.cpp"
#endif // TREENODE_H
