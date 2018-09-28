//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include <iostream>
#include <vector>
#include "146-lru-cache.h"
using namespace std;



int main(int argc, const char * argv[]) {
    LRUCache lru(3);
    lru.put(1,1);
    lru.put(2,2);
    lru.put(3,3);
    lru.put(4,4);
    cout<<lru.get(4)<<endl;
    cout<<lru.get(3)<<endl;
    cout<<lru.get(2)<<endl;
    cout<<lru.get(1)<<endl;
    lru.put(5,5);
    cout<<lru.get(5)<<endl;
    cout<<lru.get(4)<<endl;
    cout<<lru.get(3)<<endl;
    cout<<lru.get(2)<<endl;
    cout<<lru.get(1)<<endl;
    
    return 0;
}
