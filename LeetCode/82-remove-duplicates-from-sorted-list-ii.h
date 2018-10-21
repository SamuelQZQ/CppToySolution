// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
//  82-remove-duplicates-from-sorted-list-ii.h
//  CppToySolution
//
//  Created by QZQ on 21/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _2_remove_duplicates_from_sorted_list_ii_h
#define _2_remove_duplicates_from_sorted_list_ii_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// FUCK!
// 去循环一个在循环体内变的变量，不如循环一个不变的！
// 1. 链表问题边界情况包括：1.删的或增加的是 头或尾结点
// 2. 链表问题注意维护好 head、tail
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head) return head;
        
        ListNode *shead = new ListNode(-1);
        shead->next = head;
        
        ListNode *q = shead, *p;
        while(NULL != q && NULL != q->next)
        {
            p = q->next;
            while(NULL != p && NULL != p->next && p->next->val == p->val)
            {
                while(NULL != p->next && p->next->val == p->val)
                {
                    ListNode *temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                }
                
                q->next = q->next->next;
                delete p;
                p = q->next;
            }
            
            q = q->next;
            
        }
        
        head = shead->next;
        delete shead;
        return head;
    }
};

#endif /* _2_remove_duplicates_from_sorted_list_ii_h */
