//
//  SegmentTreeTest.h
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef SegmentTreeTest_h
#define SegmentTreeTest_h
# include "SegmentTree.hpp"
void Test()
{
    using namespace std;
    int a[] = {5,6,2,4,8};
    SegmentTree seg(5, a);
    cout<<seg.GetMax(0, 3)<<endl;
    seg.Update(1, 3);
    cout<<seg.GetMax(0, 3)<<endl;
    cout<<seg.GetMax(0, 4)<<endl;
    seg.Update(4, 3);
    cout<<seg.GetMax(0, 4)<<endl;
}

#endif /* SegmentTreeTest_h */
