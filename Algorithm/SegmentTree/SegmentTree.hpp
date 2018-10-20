//
//  SegmentTree.hpp
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef SegmentTree_hpp
#define SegmentTree_hpp

class SegmentTree
{
public:
    SegmentTree(int length, int *array);
    ~SegmentTree();
    
    void Update(int pos, int val) {Update(1, 0, size-1, pos, val);}
    int GetMax(int ql, int qr) {return GetMax(1, 0, size-1, ql, qr);}
private:
    void Build(int o, int l, int r, int *array);
    void Update(int o, int l, int r, int pos, int val);
    int GetMax(int o, int l, int r, int ql, int qr);
    int size;
    int *val;
};

#endif /* SegmentTree_hpp */
