//
//  Thread.cpp
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include "Thread.hpp"
Thread::Thread() : _isfree(true), _task(nullptr){
    _thread = std::thread(&Thread::run, this);
    _thread.detach(); //放到后台， join是等待线程结束
}

void Thread::add_task(Task *task){
    if(_isfree){
        _locker.lock();
        _task = task;
        _isfree = false;
        _locker.unlock();
    }
}


void Thread::run(){
    while(true){
        if(_task){
            _locker.lock();
            _isfree = false;
            _task->run();
            _isfree = true;
            _task = nullptr;
            _locker.unlock();
        }
    }
}
    
