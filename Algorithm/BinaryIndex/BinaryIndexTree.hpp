//
//  BinaryIndexTree.h
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef BinaryIndexTree_h
#define BinaryIndexTree_h
class BinaryIndexTree
{
public:
    BinaryIndexTree(int maxN);
    ~BinaryIndexTree();
    
    void modify(int x,int add);
    int getSum(int x);
    
private:
    int lowbit(int x);
    int maxN, *c;
};

#endif /* BinaryIndexTree_h */
