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

    
    AVLTree<int> numeros;
    
    for(int i=0; i<10000; i++){
        numeros.insert(rand()%1000);
    }
    
    
    
     numeros.prettyPrint(numeros.getRoot(), 0);
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    if(numeros.isAVL(numeros.getRoot()))
        cout<<"ES AVL"<<endl;
    
    
    numeros.remove(26);

    
    numeros.prettyPrint(numeros.getRoot(), 0);
    
    
    if(numeros.isAVL(numeros.getRoot()))
        cout<<"ES AVL"<<endl;
    
    
 
    


    
       
    return 0;
}
