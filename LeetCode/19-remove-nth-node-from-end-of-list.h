// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
//  19-remove-nth-node-from-end-of-list.h
//  CppToySolution
//
//  Created by QZQ on 26/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _9_remove_nth_node_from_end_of_list_h
#define _9_remove_nth_node_from_end_of_list_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 链表问题，注意处理头尾结点的特殊情况！
// 链表问题快慢指针技巧！
// 指针一定要初始化！
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = NULL, *q = NULL, *prevp = NULL;
//        ListNode *p, *q, *prevp;  因为没有初始化导致严重错误！
        q = p = head;
        
        for(int i = 0; i < n-1; ++i) q = q->next;
        while(q->next)
        {
            prevp = p;
            p = p->next;
            q = q->next;
        }
        
        if(!prevp) head = p->next;
        else prevp->next = p->next;

        delete p;
        return head;
    }
};

#endif /* _9_remove_nth_node_from_end_of_list_h */
