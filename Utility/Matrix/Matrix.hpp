//
//  Matrix.hpp
//  CppToySolution
//
//  Created by QZQ on 19/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp
#include <iostream>
#include <assert.h>

template<class T>
class Matrix
{
public:
    Matrix(int n, int m);
    Matrix(const Matrix &rhs);
    ~Matrix();
    
    void Identity();
    Matrix<T> operator * (const Matrix &y) const;
    Matrix<T>& operator = (const Matrix &y);
    Matrix<T> operator ^ (int pow) const;
    friend std::ostream & operator << (std::ostream &out, const Matrix<T> &mat)
    {
        for(int i = 0; i < mat.n; ++i)
        {
            for(int j = 0; j < mat.m; ++j)
                out<<mat.val[i][j]<<", ";
            out<<std::endl;
        }
        return out;
    }
    
private:
    void Release();
    
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
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &y)
{
    const Matrix<T> *rhs = &y;
    if(rhs == this) return *this;
    
    Release();
    n = rhs->n;
    m = rhs->m;
    
    val = new int*[n];
    for(int i = 0; i < n; ++i) val[i] = new int[m];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) val[i][j] = rhs->val[i][j];
    
    return *this;
}

template<class T>
Matrix<T>::~Matrix()
{
    Release();
}

template<class T>
void Matrix<T>::Identity()
{
    assert(this->n == this->m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) val[i][j] = i==j ? 1 : 0;
}

template<class T>
Matrix<T> Matrix<T>::operator * (const Matrix &y) const
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

template<class T>
Matrix<T> Matrix<T>::operator ^ (int pow) const
{
    assert(this->n == this->m);
    Matrix<T> ret(this->n, this->m), temp(*this);
    ret.Identity();
    
    while(pow)
    {
        if(pow & 1) ret = ret * temp;
        temp = temp * temp;
        pow >>= 1;
    }
    
    return ret;
}

template<class T>
void Matrix<T>::Release()
{
    for(int i = 0; i < n; ++i) delete [] val[i];
    delete [] val;
}

#endif /* Matrix_hpp */
