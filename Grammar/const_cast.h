//
//  const_cast.h
//  CppToySolution
//
//  Created by QZQ on 2018/11/8.
//  Copyright © 2018 QZQ. All rights reserved.
//

// const_cast 只能对内容原先不是常量的 常量指针（或常量引用）起作用。否则会出现未定义行为！
#ifndef const_cast_h
#define const_cast_h
#include <iostream>
using namespace std;
void Test() {
    
    const int b = 5;
    const int *pb = &b;
    int *pa = const_cast<int*>(pb);
    *pa = 6;    // 未定义行为
    
    cout<<b<<endl;
    cout<<*pa<<endl;
    
    
    cout<<pa<<endl;
    cout<<pb<<endl;
    cout<<&b<<endl;
}
#endif /* const_cast_h */
