//
//  main.cpp
//  Arboles
//
//  Created by Krikor Bisdikian G. on 5/9/15.
//  Copyright © 2015 Krikor Bisdikian G. All rights reserved.
//

#include <iostream>
#include "BinarySTree.h"
#include "AVLTree.h"

using namespace std;

int main(int argc, const char * argv[]) {

    
    BinarySTree<int> numeros;
    
    numeros.insert(6);
    numeros.insert(2);
    numeros.insert(5);
    numeros.insert(1);
    numeros.insert(100);
    
    cout<<numeros.getDepth()<<endl;
    
    
    numeros.inOrder();
    cout<<endl;

    
    if (numeros.search(3)) {
        cout<<"Esta"<<endl;
    }
    
    return 0;
}
