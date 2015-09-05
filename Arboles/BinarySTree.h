//
//  BinarySTree.h
//  BinaryTree
//
//  Created by Krikor Bisdikian G. on 5/9/15.
//  Copyright © 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef BinarySTree_h
#define BinarySTree_h

#include "BinaryTree.h"

template <class T>
class BinarySTree: public BinaryTree<T> {
    
    
public:
    void insertOrder(BNode<T> * root, T value);
};




#endif /* BinarySTree_h */
