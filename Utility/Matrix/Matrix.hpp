//
//  Matrix.hpp
//  CppToySolution
//
//  Created by QZQ on 19/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp
#include <stdio.h>
#include <assert.h>
template<class T>
class Matrix
{
public:
    Matrix(int n, int m);
    Matrix(const Matrix &rhs);
    ~Matrix();
    
    Matrix<T> operator * (const Matrix &y);
    Matrix<T>& operator = (const Matrix &y);
public:
    int n, m;
    T **val;
    
};

template<class T>
Matrix<T>::Matrix(int n, int m):n(n), m(m)
{
    val = new int*[n];
    for(int i = 0; i < n; ++i) val[i] = new int[m];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) val[i][j] = 0;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> &rhs):n(rhs.n), m(rhs.m)
{
    val = new int*[n];
    for(int i = 0; i < n; ++i) val[i] = new int[m];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) val[i][j] = rhs.val[i][j];
}

template<class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &rhs)
{
    if(&rhs == this) return;
    // release old memory
    // get new memory
    // do it
    
    val = new int*[n];
    for(int i = 0; i < n; ++i) val[i] = new int[m];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) val[i][j] = rhs.val[i][j];
}

template<class T>
Matrix<T>::~Matrix()
{
    for(int i = 0; i < n; ++i) delete [] val[i];
    delete [] val;
}

template<class T>
Matrix<T> Matrix<T>::operator * (const Matrix &y)
{
    const Matrix<T> *rhs = &y;
    assert(this->m == rhs->n);
    
    Matrix<T> ret(this->n, rhs->m);
    for(int i = 0; i < ret.n; ++i)
        for(int j = 0; j < ret.m; ++j)
            for(int k = 0; k < this->m; ++k)
                ret.val[i][j] += this->val[i][k] * rhs->val[k][j];
    
    return ret;
}

#endif /* Matrix_hpp */
