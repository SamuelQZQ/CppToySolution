// 线段树
//  SegmentTree.cpp
//  CppToySolution
//
//  Created by QZQ on 20/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include "SegmentTree.hpp"
#include <algorithm>

SegmentTree::SegmentTree(int length, int *array): size(length)
{
    val = new int[length * 4];
    Build(1, 0, size-1, array);
}

SegmentTree::~SegmentTree()
{
    delete [] val;
}

void SegmentTree::Build(int o, int l, int r, int *array)
{
    if(l == r) val[o] = array[l];
    else
    {
        int ls = o<<1;
        int rs = o<<1 | 1;
        int mid = l + (r-l)/2;
        Build(ls, l, mid, array);
        Build(rs, mid+1, r, array);
        val[o] = std::max(val[ls], val[rs]);
    }
}

void SegmentTree::Update(int o, int l, int r, int pos, int v)
{
    if(l==r) val[o] = v;
    else
    {
        int ls = o<<1;
        int rs = o<<1 | 1;
        int mid = l + (r-l)/2;
        
        if(pos <= mid) Update(ls, l, mid, pos, v);
        else Update(rs, mid+1, r, pos, v);
        val[o] = std::max(val[ls], val[rs]);
    }
}

int SegmentTree::GetMax(int o, int l, int r, int ql, int qr)
{
    if(ql <= l && qr >= r) return val[o];
    else
    {
        int ls = o<<1;
        int rs = o<<1 | 1;
        int mid = l + (r-l)/2;
        
        int ret = -2e9;
        if(ql <= mid) ret = std::max(ret, GetMax(ls, l, mid, ql, qr));
        if(qr > mid) ret = std::max(ret, GetMax(rs, mid+1, r, ql, qr));
        return ret;
    }
}
