//
//  MatrixTest.h
//  CppToySolution
//
//  Created by QZQ on 19/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef MatrixTest_h
#define MatrixTest_h
#include "Matrix.hpp"

static void Test()
{
    using namespace std;
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
}

#endif /* MatrixTest_h */
