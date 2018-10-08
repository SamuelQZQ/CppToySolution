//
//  Task.hpp
//  CppToySolution
//
//  Created by QZQ on 08/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <iostream>
#include <unistd.h>

class Task{
private:
    int no;
public:
    Task(int n){
        no = n;
    }
    //可以继承这个类重写该方法执行任务
    virtual void run(){
        sleep(no); //构造时决定执行几秒，模拟线程运行
        std::cout << no << "T\n";
    }
    
};
#endif /* Task_hpp */
