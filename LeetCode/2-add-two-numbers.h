//  https://leetcode.com/problems/add-two-numbers/description/
//  2-add-two-numbers.h
//  CppToySolution
//
//  Created by QZQ on 22/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef __add_two_numbers_h
#define __add_two_numbers_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remain = 0;
        ListNode *p = NULL, *q = NULL, *head = NULL;
        while(l1 || l2)
        {
            q = new ListNode(remain);
            
            if(l1)
            {
                q->val += l1->val;
                l1 = l1->next;
            }
            
            if(l2)
            {
                q->val += l2->val;
                l2 = l2->next;
            }

            remain = q->val / 10;
            q->val = q->val % 10;
            
            if(p) p->next = q;
            else head = q;
            p = q;
        }
        
        if(remain)
        {
            q = new ListNode(remain);
            p -> next = q;
        }
        return head;
    }
};

#endif /* __add_two_numbers_h */
