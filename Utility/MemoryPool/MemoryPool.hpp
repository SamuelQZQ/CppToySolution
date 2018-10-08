// http://qianzheqi.top/2018/03/20/C++%E5%86%85%E5%AD%98%E7%AE%A1%E7%90%86%EF%BC%88%E4%B8%8A%EF%BC%89%20%E6%B1%A0%E5%88%86%E9%85%8D%E5%99%A8%E3%80%81%E5%A0%86%E6%A0%88%E5%88%86%E9%85%8D%E5%99%A8/
// 内存池、对象池
//  MemoryPool.hpp
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef MemoryPool_hpp
#define MemoryPool_hpp

#include <stdio.h>
class MemoryList
{
public:
    MemoryList *next;
};

class MemoryPool
{
    union ElementPtr
    {
        MemoryList * asList;
        char * asCharPtr;
        void * asVoidPtr;
    };
    
public:
    MemoryPool(int elementSize, int elementNum);
    ~MemoryPool();
    void * Obtain();
    void Return(void *ptr);
private:
    ElementPtr head;
};
#endif /* MemoryPool_hpp */
