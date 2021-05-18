#ifndef AVL_H
#define AVL_H

#include "indextree.h"

namespace yixi {

template <typename T>
struct AVLNode : public IndexTreeNode<T> {
    int high_;
    AVLNode(const T &obj) : IndexTreeNode<T>(obj), high_(0){

    }
    AVLNode() : IndexTreeNode<T>(), high_(0){

    }
};

template <typename T>
class AVL : public IndexTree<T> {
    bool insert(AVLNode<T>** root, AVLNode<T>* obj);
    void LL(AVLNode<T>** root);
    void LR(AVLNode<T>** root);
    void RR(AVLNode<T>** root);
    void RL(AVLNode<T>** root);
public:
    AVL(const T &obj);
    AVL(AVLNode<T> *node = nullptr);
    virtual bool insert(IndexTreeNode<T>* obj);
};

}

#include "../src/avl.cpp"

#endif