//
//  Thread.hpp
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef Thread_hpp
#define Thread_hpp

#include <thread>
#include "Task.hpp"

class Thread{
private:
    std::thread _thread;
    bool _isfree;
    Task *_task;
    std::mutex _locker;
public:
    Thread();
    bool isfree(){return _isfree;}
    void add_task(Task *task);
    
    //如果有任务则执行任务，否则自旋
    void run();
    
};
#endif /* Thread_hpp */
