//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Matrix<int> A(2,2);
    A.val[0][0] = 1; A.val[0][1] = 1;
    A.val[1][0] = 2; A.val[1][1] = 1;
    
    Matrix<int> B(3,2);
    B.val[0][0] = 2; B.val[0][1] = 1;
    B.val[1][0] = 1; B.val[1][1] = 1;
    B.val[2][0] = 2; B.val[2][1] = 2;
    Matrix<int> C = A^3;
    
    cout<<(A^2)<<endl;
    
    cout<<(A^3)<<endl;
    return 0;
}
