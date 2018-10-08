//
//  ThreadPool.cpp
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include "ThreadPool.hpp"



ThreadPool::ThreadPool(int n){
    while(n--){
        Thread *t = new Thread();
        _pool.push_back(t);
    }
    std::thread main_thread(&ThreadPool::run, this);
    main_thread.detach();
}

ThreadPool::~ThreadPool(){
    for(int i = 0;i < _pool.size(); ++i){
        delete _pool[i];
    }
}

void ThreadPool::add_task(Task *task){
    _locker.lock();
    task_queue.push(task);
    _locker.unlock();
}

void ThreadPool::run(){
    while(true){
        _locker.lock();
        if(task_queue.empty()){
            _locker.unlock();
            continue;
        }
        // 寻找空闲线程执行任务
        for(int i = 0; i < _pool.size(); ++i){
            if(_pool[i]->isfree()){
                _pool[i]->add_task(task_queue.front());
                task_queue.pop();
                break;
            }
        }
        _locker.unlock();
    }
}



