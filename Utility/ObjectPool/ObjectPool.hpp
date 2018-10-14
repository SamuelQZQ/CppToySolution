//
//  ObjectPool.hpp
//  CppToySolution
//
//  Created by QZQ on 14/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef ObjectPool_hpp
#define ObjectPool_hpp

#include <stdio.h>
template<typename Object>
class ObjectPool
{
public:
    ObjectPool(size_t size):size(size)
    {
        for(size_t i=0; i < size; ++i)
        {
            pool.push_back(new Object());
        }
    }
    
    ~ObjectPool()
    {
        for(auto it = pool.begin(); it != pool.end(); ++it)
        {
            delete(*it);
        }
    }
    
    Object* GetObject()
    {
        Object* pObj=NULL;
        if(0==size)
        {
            pObj=new Object();
        }
        else
        {
            pObj=pool.back();
            pool.pop_back();
            --size;
        }
        return pObj;
    }
    
    void ReturnObject(Object* pObj)
    {
        pool.push_back(pObj);
        ++size;
    }
private:
    size_t size;
    std::list<Object*> pool;
};
#endif /* ObjectPool_hpp */
