//
//  MemoryPoolTest.h
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef MemoryPoolTest_h
#define MemoryPoolTest_h
#include "MemoryPool.hpp"

void Test()
{
    using namespace std;
    MemoryPool pool(32, 2);
    
    void * p1 = pool.Obtain();
    cout<<p1<<endl;
    
    void * p2 = pool.Obtain();
    cout<<p2<<endl;
    
    pool.Return(p1);
    void * p3 = pool.Obtain();
    cout<<p3<<endl;
    
    pool.Return(p2);
    void * p4 = pool.Obtain();
    cout<<p4<<endl;
    
    void * p5 = pool.Obtain();
    cout<<p5<<endl;
}
#endif /* MemoryPoolTest_h */
