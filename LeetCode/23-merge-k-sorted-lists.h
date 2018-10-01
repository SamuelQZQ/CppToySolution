// https://leetcode.com/problems/merge-k-sorted-lists/description/
//  23-merge-k-sorted-lists.h
//  CppToySolution
//
//  Created by QZQ on 01/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _3_merge_k_sorted_lists_h
#define _3_merge_k_sorted_lists_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// priority_queue的用法要注意
// 一些小的语法问题
// 建议重写一遍！
// 后面有自己最初的写法
struct comp{
    bool operator () (const ListNode* a, const ListNode* b) {
        return a->val >= b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        for(int i = 0, sz = lists.size(); i < sz; ++i) {
            if(lists[i]) q.push(lists[i]);
        }
        
        ListNode l(-1);
        ListNode *temp = &l;
        ListNode *head = temp;
        while(!q.empty()) {
            ListNode *top = q.top();
            q.pop();
            
            temp->next = top;
            temp = temp->next;
            if(top->next) q.push(top->next);
        }
        return head->next;
    }
};

// 原写法 worse~
struct Node{
    ListNode *p;
};

bool operator < (const Node &a, const Node &b) {
    return a.p->val >= b.p->val;
}

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        for(int i = 0, sz = lists.size(); i < sz; ++i) {
            if(lists[i]) q.push(Node{lists[i]});
        }
        
        ListNode l(-1);
        ListNode *temp = &l;
        ListNode *head = temp;
        while(!q.empty()) {
            Node top = q.top();
            q.pop();
            
            temp->next = top.p;
            temp = temp->next;
            if(top.p->next) q.push(Node{top.p->next});
        }
        return head->next;
    }
};



#endif /* _3_merge_k_sorted_lists_h */
