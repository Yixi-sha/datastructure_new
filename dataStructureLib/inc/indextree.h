#ifndef INDEXTREE_H
#define INDEXTREE_H

#include "object.h"
#include "itnode.h"
#include "linklist.h"

namespace yixi {

template <typename T>
struct IndexTreeNode : public Object{
    T val_;
    struct IndexTreeNode *left_;
    struct IndexTreeNode *right_;
    IndexTreeNode(): left_(nullptr), right_(nullptr) {
    }
    IndexTreeNode(const T &obj) :val_(obj), left_(nullptr), right_(nullptr) {

    }
};

template <typename T>
class IndexTree : public Object {
protected:
    IndexTreeNode<T>* root_;
    virtual IndexTreeNode<T> *find(IndexTreeNode<T>* root, const T &obj) {
        if(root->val_ == obj){
            return root;
        }
        if(root->val_ > obj && root->left_){
            return find(root->left_, obj);
        }else if(root->val_ < obj && root->right_){
            return find(root->right_, obj);
        }
        return root;
    }
public:
    IndexTree(){
        root_ = nullptr;
    }
    virtual bool insert(IndexTreeNode<T>* obj) = 0;
//    virtual void getLinkList(LinkList<T>* obj) = 0;
    virtual bool find(T &obj){
        if(!this->root_){
            return false;
        }
        IndexTreeNode<T> *ret = find(this->root_, obj);
        if(ret->val_ == obj){
            obj = ret->val_;
            return true;
        }
        return false;
    }
    //virtual void BSP();
};

} // yixi

#include "../src/indextree.cpp"

#endif