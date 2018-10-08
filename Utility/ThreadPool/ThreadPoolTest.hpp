//
//  ThreadPoolTest.h
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef ThreadPoolTest_h
#define ThreadPoolTest_h

#include "ThreadPool.hpp"

void Test(){
    ThreadPool tp(2);
    
    Task t1(1);
    Task t2(3);
    Task t3(2);
    
    tp.add_task(&t1);
    tp.add_task(&t2);
    tp.add_task(&t3);
    
    sleep(4);   //等待调度器结束，不然会崩溃
}

#endif /* ThreadPoolTest_h */
