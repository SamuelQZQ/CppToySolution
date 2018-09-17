//
//  QuickSort.h
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h
static int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) ++low;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

static void QuickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivotpos = Partition(arr, low, high);
    QuickSort(arr, low, pivotpos-1);
    QuickSort(arr, pivotpos+1, high);
}

#endif /* QuickSort_h */
