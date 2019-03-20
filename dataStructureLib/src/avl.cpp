#ifndef AVL_CPP
#define AVL_CPP

#include "../inc/avl.h"
#include "../inc/exception.h"

#include <iostream>

using namespace std;

namespace yixi
{

template <typename T>
int Avl<T>::getDegree(ITNode<T>* root)
{
    int ret = 0;   
    if(root != nullptr)
    {
        ret = 1;
        int left = getDegree(root->mleft);
        int right = getDegree(root->mright);
        ret += (left > right) ? left : right;
    }

    return ret;
}

template <typename T>
bool Avl<T>::insert(ITNode<T>* obj, ITNode<T>* root)
{
    bool ret = (obj != nullptr);
    if(ret)
    {   
        if(obj->value == root->value)
            ret = false;
        if(ret)
        {
            if( (obj->value) > (root->value) )
            {
                if(root->mright == nullptr)
                    root->mright = obj;
                else
                    ret = insert(obj, root->mright);
            }
            else
            {
                if(root->mleft == nullptr)
                    root->mleft = obj;
                else
                    ret = insert(obj, root->mleft);
            }  
        }
              
           
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException, "Invalid Parameter in  Avl<T>::insert");
    }

    return ret;
}

template <typename T>
int Avl<T>::adjust(ITNode<T>* obj, ITNode<T>* root)
{
    int ret  = 0;
    if(obj->mleft)
        ret = adjust(obj->mleft, obj);
    if(ret != 2)
    {
        if(obj->mright)
        ret = adjust(obj->mright, obj);
    }
    
    if(ret != 2)
    {
        int left = getDegree(obj->mleft);
        int right = getDegree(obj->mright);
        if(left > right)
        {
            ret =  (left - right);
            if( ret == 2 )
            {     
                ITNode<T>* rootNode = obj->mleft;
                ITNode<T>* rightNode = obj;
                rightNode->mleft = nullptr;

                ITNode<T>* midNode = rootNode->mright;
                ITNode<T>* leftNode = rootNode->mleft;
                        
                int mid = getDegree(midNode);
                left = getDegree(leftNode);
                if(mid < left)
                {
                    rootNode->mright = rightNode;                    
                    rootNode->mleft = leftNode;
                    rightNode->mleft = midNode;
                        
                }
                else
                {
                    if(midNode->mleft != nullptr)
                    {
                        rightNode->mleft = midNode->mleft;
                    }
                    else
                    {
                        rightNode->mleft = midNode->mright;
                    }
                    midNode->mleft = rootNode;
                    rootNode->mright = nullptr;
                    midNode->mright = rightNode;
                    rootNode = midNode;
                }
                if(root == nullptr)
                    this->mroot = rootNode;
                else
                {
                    if( (root->value) > (rootNode->value) )
                    {
                        root->mleft = rootNode;
                    }
                    else
                    {
                        root->mright = rootNode;
                    }        
                } 
                    
            }                      
        }
        else
        {
            ret =  (right - left);
            if(ret == 2)
            {   
            
                ITNode<T>* rootNode = obj->mright;
                ITNode<T>* leftNode = obj;
                leftNode->mright = nullptr;

                ITNode<T>* midNode = rootNode->mleft;
                ITNode<T>* rightNode = rootNode->mright;

                int mid = getDegree(midNode);
                right = getDegree(leftNode);

                if(right > mid)
                {
                    leftNode->mright = midNode;
                    rootNode->mleft = leftNode;
                    rootNode->mright = rightNode;
                }
                else
                {
                    if(midNode->mright != nullptr)
                    {
                        leftNode->mright = midNode->mright;
                    }
                    else
                    {
                        leftNode->mright = midNode->mleft;
                    }
                    midNode->mright = rootNode;
                    rootNode->mleft = nullptr;
                    midNode->mleft = leftNode;
                    rootNode = midNode;                   
                }
                if(root == nullptr)
                    this->mroot = rootNode;
                else
                {
                    if( (root->value) > (rootNode->value) )
                    {
                        root->mleft = rootNode;
                    }
                    else
                    {
                        root->mright = rootNode;
                    }        
                }  
            }
        }
    }
    
    return ret;   
}

template <typename T>
bool Avl<T>::insert(ITNode<T>* obj)
{
    bool ret = (obj != nullptr);
    
    if(ret)
    {
        if(this->mroot == nullptr)
        {
            this->mroot = obj;
        }
        else
        {
            ret = insert(obj, this->mroot); 
            if(ret)
                adjust(this->mroot, nullptr);   
        }
        
        
            
                   
    }
    else
    {
        THROW_EXCEPTION(InvalidParameterException, "Invalid Parameter in  Avl<T>::insert");
    }
    return ret;
}

template <typename T>
void Avl<T>::getLinkList(LinkList<T>* obj, ITNode<T>* root)
{
    if(root != nullptr)
    {
        cout << "root " <<root->value;
        if(root->mleft)
            cout << "  left " <<root->mleft->value;
        if(root->mright)
            cout << "  right " <<root->mright->value << endl;
        else
            cout <<endl;
        getLinkList(obj, root->mleft);
        obj->insert( root->value );
        getLinkList(obj, root->mright);
    }
}

template <typename T>
void Avl<T>::getLinkList(LinkList<T>* obj)
{
    getLinkList(obj, this->mroot);
}

}

#endif