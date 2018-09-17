//
//  BinaryIndexTreeTest.h
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef BinaryIndexTreeTest_h
#define BinaryIndexTreeTest_h
#include "BinaryIndexTree.h"
#include <iostream>

static void Test()
{
    using namespace std;
    BinaryIndexTree b = BinaryIndexTree(10);
    b.modify(2, 1);
    b.modify(4, 1);
    cout<<b.getSum(2)<<endl;
    cout<<b.getSum(3)<<endl;
    cout<<b.getSum(4)<<endl;
}

#endif /* BinaryIndexTreeTest_h */
