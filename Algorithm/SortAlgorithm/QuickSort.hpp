//
//  QuickSort.h
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h
#include<algorithm>

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

// 普通
static void QuickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivotpos = Partition(arr, low, high);
    QuickSort(arr, low, pivotpos-1);
    QuickSort(arr, pivotpos+1, high);
}

// 非递归快排
static void QuickSortStack(int arr[], int low, int high) {
    vector<pair<int, int>> stack;
    stack.push_back(make_pair(low, high));
    while(0 != stack.size())
    {
        int l = stack.back().first;
        int r = stack.back().second;
        stack.pop_back();
        if(l >= r) continue;
        int pivotpos = Partition(arr, l, r);
        stack.push_back(make_pair(l, pivotpos-1));
        stack.push_back(make_pair(pivotpos+1, r));
    }
}

/* * * * * *
* 链表快排
*/

// 结点定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v = 0):val(v), next(NULL) {}
};


static ListNode* Partition(ListNode *head, ListNode *tail)
{
    ListNode *pivot = head->next;
    
    ListNode *p = pivot->next;
    pivot->next = tail;
    
    while(p != tail)
    {
        ListNode *temp = p->next;
        if(p->val < pivot->val)
        {
            p->next = head->next;
            head->next = p;
        }
        else
        {
            p->next = pivot->next;
            pivot->next = p;
        }
        p = temp;
    }
    return pivot;
}

// 为了方便，头结点不存数据，只作为辅助
// 尾结点也只作为辅助，不在排序内
static void QuickSort(ListNode *head, ListNode *tail)
{
    if(head->next == tail) return;
    ListNode *pivot = Partition(head, tail);
    QuickSort(head, pivot);
    QuickSort(pivot, tail);
}
#endif /* QuickSort_h */
