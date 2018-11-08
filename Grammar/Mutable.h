//
//  Mutable.h
//  CppToySolution
//
//  Created by QZQ on 2018/11/8.
//  Copyright © 2018 QZQ. All rights reserved.
//


/******
 * mutable 不仅能突破const成员函数的限制，还能突破const object的限制
 */
#ifndef Mutable_h
#define Mutable_h
#include <iostream>
using namespace std;

class MClass
{
public:
    mutable int a;
    
    void func() const {
        a = 102;
    }
};

void Test()
{
    const MClass m;
    m.a = 100;
    cout<<m.a<<endl;
    
    m.func();
    cout<<m.a<<endl;
}

#endif /* Mutable_h */
