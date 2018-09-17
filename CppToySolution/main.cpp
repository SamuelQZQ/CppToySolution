//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include <iostream>
#include "BigNumber.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
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
    return 0;
}
