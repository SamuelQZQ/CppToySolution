//
//  ThreadPool.hpp
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef ThreadPool_hpp
#define ThreadPool_hpp

#include <queue>
#include <vector>
#include <mutex>
#include "Task.hpp"
#include "Thread.hpp"

class ThreadPool{
private:
    std::queue<Task *> task_queue;
    std::vector<Thread *> _pool;
    std::mutex _locker;
    
public:
    //构造线程并后台执行，默认数量为10
    ThreadPool(int n = 10);
    ~ThreadPool();
    //添加任务
    void add_task(Task *task);
    //轮询
    void run();
};
#endif /* ThreadPool_hpp */
