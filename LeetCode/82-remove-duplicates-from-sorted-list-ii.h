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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head) return head;
        
        ListNode *p = head;
        while(p != NULL)
        {
            while(NULL != p->next && p->next->val == p->val)
            {
                delete p->next;
                p->next = p->next->next;
            }
            p = p->next;
        }
        return head;
    }
};

#endif /* _2_remove_duplicates_from_sorted_list_ii_h */
