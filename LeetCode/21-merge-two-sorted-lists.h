// https://leetcode.com/problems/merge-two-sorted-lists/description/
//  21-merge-two-sorted-lists.h
//  CppToySolution
//
//  Created by QZQ on 29/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _1_merge_two_sorted_lists_h
#define _1_merge_two_sorted_lists_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//struct ListNode {
//        int val;
//        ListNode *next;
//        ListNode(int x) : val(x), next(NULL) {}
//    };

// Why am I so stupid?????

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *p = NULL;
        ListNode temp(-1);
        head = &temp;
        p = head;
        while(l1 || l2)
        {
            if(NULL == l2) {
                p->next = l1;
                l1 = l1->next;
            }
            else if(NULL == l1) {
                p->next = l2;
                l2 = l2->next;
            }
            else if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            
            p = p->next; // 遗漏
        }

        return head->next;
    }
};

#endif /* _1_merge_two_sorted_lists_h */
