//
//  BigNumberTest.h
//  CppToySolution
//
//  Created by QZQ on 17/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef BigNumberTest_h
#define BigNumberTest_h
#include <iostream>
#include "BigNumber.hpp"
static void Test()
{
    using namespace std;
    cout<<"***Test for output***"<<endl;
    cout<<BigNumber(100000)<<endl;
    cout<<BigNumber(-100000)<<endl;
    cout<<BigNumber(-1234567)<<endl;
    cout<<BigNumber(1234567)<<endl;
    
    cout<<"***Test for add***"<<endl;
    cout<<BigNumber(1234567) + BigNumber(-1234568)<<endl;
    cout<<BigNumber(1234567) + BigNumber(-11234567)<<endl;
    cout<<BigNumber(-1234567) + BigNumber(-11234567)<<endl;
    cout<<BigNumber(1234567) + BigNumber(11234567)<<endl;
    
    cout<<"***Test for multiply***"<<endl;
    cout<<BigNumber(100) * BigNumber(2)<<endl;
    cout<<BigNumber(-122) * BigNumber(-200)<<endl;
    cout<<BigNumber(100) * BigNumber(-100)<<endl;
    cout<<BigNumber(1001) * BigNumber(900)<<endl;
}

#endif /* BigNumberTest_h */
