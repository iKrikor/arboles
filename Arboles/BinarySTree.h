//
//  BinarySTree.h
//  BinaryTree
//
//  Created by Krikor Bisdikian G. on 5/9/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#ifndef BinarySTree_h
#define BinarySTree_h

#include "BinaryTree.h"

template <class T>
class BinarySTree: public BinaryTree<T> {
    
    
public:
    BinarySTree();
    ~BinarySTree();
    
    void insert(T value);
    bool search(const T value) const;
    bool search(const T value, BNode<T> * node) const;
};

template <class T>
BinarySTree<T>::BinarySTree() : BinaryTree<T>(){}

template <class T>
BinarySTree<T>::~BinarySTree()
{
    
}

template <class T>
void BinarySTree<T>::insert(T value){
    this->insertO(value);
}
template <class T>
bool BinarySTree<T>::search(const T value) const{
    return search(value, this->root);

}

template <class T>
bool BinarySTree<T>::search(const T value, BNode<T> * node)const {
    if (node == nullptr)
    {
        return false;
    }
    else {
        T value2 = node->getInfo();
        if (value == value2)
        {
            return true;
        }
        else if (value < value2)
        {
            return search(value, node->getLeft());
        }
        else {
            return search(value, node->getRight());
        }
    }
}





#endif /* BinarySTree_h */
