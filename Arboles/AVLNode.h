//
//  AVLNode.h
//  Arboles
//
//  Created by Krikor Bisdikian G. on 6/9/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#ifndef AVLNode_h
#define AVLNode_h

#include "BNode.h"

template <class T>
class AVLNode : public BNode<T> {
    int height = 1;
    
public:
    AVLNode() {}
    virtual ~AVLNode();
    int getHeight(){
        return height;
    }
    void setHeight(int newHeight){
        height= newHeight;
    }
};

template <class T>
AVLNode<T>::~AVLNode(){
    BNode<T>::info.~T();
    BNode<T>::left=BNode<T>::right=BNode<T>::parent= nullptr;
    
}


#endif /* AVLNode_h */
