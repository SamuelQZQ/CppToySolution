//
//  main.cpp
//  CppToySolution
//
//  Created by QZQ on 16/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//


#include <list>
#include <map>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "QuickSort.hpp"


int main()
{
    ListNode *all = new ListNode[10];
    
    for(int i = 1; i < 10; ++i)
    {
        all[i].val = i * 10086 % 23;
        cout<<all[i].val<<endl;
        all[i-1].next = all+i;
    }
    
    cout<<"***"<<endl;
    QuickSort(all, NULL);
    
    ListNode *p = all;
    while(p != NULL)
    {
        cout<<p->val<<endl;
        p = p->next;
    }
    
}
