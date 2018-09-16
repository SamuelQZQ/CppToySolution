//
//  BinaryIndexTree.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include <stdio.h>
#include "BinaryIndexTree.h"

BinaryIndexTree::BinaryIndexTree(int maxN)
{
    this->maxN = maxN;
    c = new int[maxN]();
}

BinaryIndexTree::~BinaryIndexTree()
{
    delete [] c;
}

int BinaryIndexTree::lowbit(int x)
{
    return x & (-x);
}

void BinaryIndexTree::modify(int x,int add)
{
    while(x<=maxN)
    {
        c[x]+=add;
        x+=lowbit(x);
    }
}
int BinaryIndexTree::getSum(int x)
{
    int ret=0;
    while(x!=0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
