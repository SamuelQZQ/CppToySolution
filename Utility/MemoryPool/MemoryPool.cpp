//
//  MemoryPool.cpp
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include "MemoryPool.hpp"
#include <memory>
#include <assert.h>
MemoryPool::MemoryPool(int elementSize, int elementNum)
{
    assert(elementSize > sizeof(MemoryList));
    
    head.asVoidPtr = malloc( (elementNum+1) * elementSize);
    int step = elementSize/sizeof(char);
    
    ElementPtr end;
    end.asCharPtr = head.asCharPtr + (elementNum+1) * step;
    
    ElementPtr current, prev;
    prev = head;
    current.asCharPtr = prev.asCharPtr+step;
    while(current.asCharPtr < end.asCharPtr)
    {
        prev.asList->next = current.asList;
        prev = current;
        current.asCharPtr = current.asCharPtr + step;
    }
    
    current.asList->next = nullptr;
}

MemoryPool::~MemoryPool()
{
    free(head.asVoidPtr);
}

void * MemoryPool::Obtain()
{
    if(nullptr == head.asList->next) return nullptr;
    else
    {
        ElementPtr ret;
        ret.asList = head.asList->next;
        head.asList->next = ret.asList->next;
        return ret.asVoidPtr;
    }
}

void MemoryPool::Return(void *ptr)
{
    MemoryList *listNode = static_cast<MemoryList*>(ptr);
    listNode->next = head.asList->next;
    head.asList->next = listNode;
}
