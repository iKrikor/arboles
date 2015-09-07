//
//  AVLTree.h
//  Arboles
//
//  Created by Krikor Bisdikian G. on 6/9/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "AVLNode.h"


template <class T>
class AVLTree {
    AVLNode<T> * root = nullptr;
    
    
public:
    AVLTree(){}
    ~AVLTree();
    
    
    bool empty();
    
    void clear();
    void clear(AVLNode<T> * node);
    
    AVLNode<T> * getRoot() const;
    void setRoot(AVLNode<T> * node);
    
    void rRotate(AVLNode<T> * y);
    void lRotate(AVLNode<T> * x);
    
    void insert(T value);
    void insert(AVLNode<T> * parent, AVLNode<T> * node);
    
    void preOrder() const;
    void preOrder(AVLNode<T> * node) const;
    
    
    void inOrder() const;
    void inOrder(AVLNode<T> * node) const;
    
    void postOrder() const;
    void postOrder(AVLNode<T> * node) const;
    
    void isLeaf() const;
    void isLeaf(AVLNode<T> * node) const;
    
    void ancestors(AVLNode<T> * node) const;
    
    int getHeight() const;
    int getHeight(AVLNode<T> * node) const ;
    
    int getDepth() const;
    int getDepth(AVLNode<T> * node) const;
    
    int getLevel() const;
    int getLevel(AVLNode<T> * node) const;
    
    int getBalanceFactor() const;
    int getBalanceFactor(AVLNode<T> * node) const ;
    
    int maxHeight(int leftHeight, int rightHeight){
        if(leftHeight > rightHeight){
            return leftHeight;
        }else{
            return rightHeight;
        }
    }
};

    
    template <class T>
    void AVLTree<T>::rRotate(AVLNode<T> * y){
        AVLNode<T> * x = y->getRight();
        AVLNode<T> * temp = x->getRight();
        
        x->setRight(y);
        y->setLeft(temp);
        
        y->setHeight(maxHeight(y->getLeft()->getHeight(), y->getRight()->getHeight()) + 1);
        x->setHeight(maxHeight(x->getLeft()->getHeight(), x->getRight()->getHeight()) + 1);
        
    }
    
    
    template <class T>
    void AVLTree<T>::lRotate(AVLNode<T> * x){
        AVLNode<T> * y = x->getRight();
        AVLNode<T> * temp = y->getLeft();
        
        x->setLeft(x);
        y->setRight(temp);
        
        
        x->setHeight(maxHeight(x->getLeft()->getHeight(), x->getRight()->getHeight()) + 1);
        y->setHeight(maxHeight(y->getLeft()->getHeight(), y->getRight()->getHeight()) + 1);

    }

template <class T>
void AVLTree<T>::insert(T value){
    AVLNode<T> * node = new AVLNode<T>(value);
    insert(root, node);
}


    template <class T>
    void AVLTree<T>::insert(AVLNode<T> * parent, AVLNode<T> * node){
        if (empty())
        {
            setRoot(node);
        }
        else
        {
            if(node->getInfo() < parent->getInfo())
            {
                
                if (parent->getLeft() == nullptr)
                {
                    parent->setLeft(node);
                    node->setParent(parent);
                }
                else
                {
                    insert(parent->getLeft(), node);
                }
            }
            else
            {
                if (parent->getRight() == nullptr)
                {
                    parent->setRight(node);
                    node->setParent(parent);
                }
                else
                {
                    insert(parent->getRight(), node);
                }
            }
        }
        
        parent->setHeight(maxHeight(parent->getLeft()->getHeight(), parent->getRight()->getHeight()) + 1);
        
        int balance = getBalanceFactor(parent);
        
        if(balance > 1 && node->getInfo()< parent->getLeft()->getInfo()){
            rRotate(parent);
        }
        
        if(balance<-1 && node->getInfo()> parent->getRight()->getInfo()){
            lRotate(parent);
        }
        
        if(balance > 1 && node->getInfo()> parent->getLeft()->getInfo()){
            
            rRotate(parent);
        }
        
        if(balance<-1 && node->getInfo()< parent->getRight()->getInfo()){
            lRotate(parent);
        }

        
    }
    
    template <class T>
    AVLTree<T>::~AVLTree()
    {
        clear();
    }
    
    template <class T>
    bool AVLTree<T>::empty()
    {
        return root == nullptr;
    }
    
    template <class T>
    void AVLTree<T>::clear()
    {
        clear(root);
    }
    
    template <class T>
    void AVLTree<T>::clear(AVLNode<T> * node)
    {
        if (node) {
            clear(node->getLeft());
            clear(node->getRight());
            
            delete node;
        }
    }
    
    template <class T>
    AVLNode<T> * AVLTree<T>::getRoot() const
    {
        return root;
    }
    
    template <class T>
    void AVLTree<T>::setRoot(AVLNode<T> * node)
    {
        if (!empty()) {
            node->setLeft(root);
            root->setParent(node);
            root = node;
        }
        else {
            root = node;
        }
    }

    
    template <class T>
    void AVLTree<T>::preOrder() const
    {
        preOrder(root);
    }
    
    template <class T>
    void AVLTree<T>::preOrder(AVLNode<T> * node) const
    {
        if (node) {
            /* Procesar el nodo */
            std::cout << *node << std::endl;
            
            /* Invocar a los hijos */
            preOrder(node->getLeft());
            preOrder(node->getRight());
            
        }
    }
    
    template <class T>
    void AVLTree<T>::inOrder() const
    {
        inOrder(root);
    }
    
    template <class T>
    void AVLTree<T>::inOrder(AVLNode<T> * node) const
    {
        if (node) {
            
            /* Invocar al hijo izquierdo */
            inOrder(node->getLeft());
            
            /* Procesar el nodo */
            std::cout << *node << std::endl;
            
            /* Invocar al hijo derecho */
            inOrder(node->getRight());
        }
    }
    
    template <class T>
    void AVLTree<T>::postOrder() const
    {
        postOrder(root);
    }
    
    template <class T>
    void AVLTree<T>::postOrder(AVLNode<T> * node) const
    {
        if (node) {
            /* Invocar a los hijos */
            postOrder(node->getLeft());
            postOrder(node->getRight());
            
            /* Procesar el nodo */
            std::cout << *node << std::endl;
        }
    }
    
    template <class T>
    void AVLTree<T>::isLeaf() const
    {
        isLeaf(root);
    }
    
    template <class T>
    void AVLTree<T>::isLeaf(AVLNode<T> * node) const
    {
        if (node) {
            if (!node->getLeft() && !node->getRight()) {
                std::cout << *node << std::endl;
            }
            else {
                isLeaf(node->getLeft());
                isLeaf(node->getRight());
            }
        }
    }
    
    template <class T>
    void AVLTree<T>::ancestors(AVLNode<T> * node) const
    {
        if (node) {
            std::cout << *node << " -> ";
            ancestors(node->getParent());
        }
    }
    
    template <class T>
    int AVLTree<T>::getHeight() const
    {
        return getHeight(root);
    }
    
    template <class T>
    int AVLTree<T>::getHeight(AVLNode<T> * node) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            node->getHeight();
        }
    }

    
    template <class T>
    int AVLTree<T>::getDepth() const
    {
        return getDepth(root);
    }
    
    template <class T>
    int AVLTree<T>::getDepth(AVLNode<T> * node) const
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return getDepth(node->getParent()) + 1;
        }
    }
    
    template <class T>
    int AVLTree<T>::getLevel() const
    {
        return getLevel(root);
    }
    
    template <class T>
    int AVLTree<T>::getLevel(AVLNode<T> * node) const
    {
        return getDepth(node) +1;
    }
    
    template <class T>
    int AVLTree<T>::getBalanceFactor() const
    {
        return getBalanceFactor(root);
    }
    
    template <class T>
    int AVLTree<T>::getBalanceFactor(AVLNode<T> * node) const
    {
        return  getHeight(node->getLeft()) - getHeight(node->getRight());
    } 

    





#endif /* AVLTree_h */
