#ifndef GTREENODE_H
#define GTREENODE_H

#include "treenode.h"
#include "linklist.h"

namespace yixi
{

template <typename T>
class GTreeNode : public TreeNode<T>
{
public:
    LinkList< GTreeNode<T>*> child;
};

}

#endif // GTREENODE_H
