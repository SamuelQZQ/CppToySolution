//
//  HeapSort.h
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h
#include <algorithm>
static void AdjustHead(int arr[], int k, int n)
{
    int temp = arr[k];
    for(int i = k*2+1; i < n; i = k*2+1)
    {
        if(i+1 < n && arr[i+1] > arr[i]) i++;
        if(arr[i] > temp)
        {
            arr[k] = arr[i];
            k = i;
        }
        else break;
    }
    arr[k] = temp;
}

static void CreateHeap(int arr[], int n)
{
    for(int i = n/2-1; i >= 0; --i) AdjustHead(arr, i, n);
}

static void HeapSort(int arr[], int n)
{
    CreateHeap(arr,n);
    for(int i = n-1; i > 0; --i)
    {
        std::swap(arr[0], arr[i]);
        AdjustHead(arr, 0, i);
    }
}

#endif /* HeapSort_h */
