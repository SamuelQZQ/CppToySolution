//
//  SortTest.h
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef SortTest_h
#define SortTest_h
#include <iostream>
#include "QuickSort.h"
#include "HeapSort.h"

static void Print(int *arr, int len)
{
    for(int i = 0; i < len; ++i)
        std::cout<<arr[i]<<' ';
    std::cout<<std::endl;
}

static void Test()
{
    using namespace std;
    int arr[] = {1,2,3,4,5,6,7,8};
    unsigned int len = sizeof(arr)/sizeof(int);
    
    cout<<"quick sort"<<endl;
    random_shuffle(arr, arr+len);
    Print(arr,len);
    QuickSort(arr, 0, len);
    Print(arr,len);
    
    cout<<"heap sort"<<endl;
    random_shuffle(arr, arr+len);
    Print(arr,len);
    HeapSort(arr, len);
    Print(arr,len);
}

#endif /* SortTest_h */
