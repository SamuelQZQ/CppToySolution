// https://leetcode.com/problems/lru-cache/description/
//  146-lru-cache.h
//  CppToySolution
//
//  Created by QZQ on 28/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef _46_lru_cache_h
#define _46_lru_cache_h
#include<unordered_map>
// 链表插入不熟悉
// 先把周围结点指向要插入结点，再把插入结点指向周围结点。不要遗漏
// 头尾结点着重考虑！
using namespace std;

class LRUCache {
    struct ListNode {
        int key, val;
        ListNode *next, *prev;
    };
    
public:
    LRUCache(int capacity) {
        nodePool = new ListNode[capacity];
        head = &nodePool[0];
        tail = &nodePool[capacity-1];
        for(int i = 0; i < capacity; ++i)
        {
            if(i != capacity-1) nodePool[i].next = &nodePool[i+1];
            else nodePool[i].next = NULL;
            
            if(i != 0) nodePool[i].prev = &nodePool[i-1];
            else nodePool[i].prev = NULL;
            
            nodePool[i].key = -1;
        }
    }
    
    ~LRUCache() {
        delete [] nodePool;
    }
    
    int get(int key) {
        if(table.find(key) == table.end()) return -1;
        else
        {
            ListNode *ansPtr = table[key];
            RemoveSelf(ansPtr);
            if(NULL != head) InsertSelfBefore(ansPtr, head);
            else // capacity == 1
            {
                ansPtr->next = ansPtr->prev = NULL;
                head = tail = ansPtr;
            }
            
            return ansPtr->val;
        }
    }
    
    void put(int key, int value) {
        ListNode *newPtr = NULL;
        if(table.find(key) == table.end()) newPtr = tail;
        else newPtr = table[key];
        
        RemoveSelf(newPtr);
        if(NULL != head) InsertSelfBefore(newPtr, head);
        else // capacity == 1
        {
            newPtr->next = newPtr->prev = NULL;
            head = tail = newPtr;
        }
        
        if(newPtr->key != -1) table.erase(newPtr->key);
        newPtr->key = key;
        newPtr->val = value;
        table[key] = newPtr;
    }
    
private:
    void RemoveSelf(ListNode *p)
    {
        // notice
        // ! p is head or tail
        // ! 长度为1的链表
        if(NULL == p) return; // assert~
        
        if(p->next) p->next->prev = p->prev;
        if(p->prev) p->prev->next = p->next;
        if(head == p && tail == p) head = tail = NULL;
        if(p == head) head = p->next;
        if(p == tail) tail = p->prev;
    }
    
    void InsertSelfBefore(ListNode *p, ListNode*q)
    {
        // notice
        // ! q是头结点
        if(NULL == p || NULL == q) return; // assert
        
        p->prev = q->prev;
        p->next = q;
        
        if(q->prev) q->prev->next = p;
        q->prev = p;
        
        if(head == q) head = p;
    }
    
    ListNode *nodePool;
    ListNode *head, *tail;
    unordered_map<int, ListNode*> table;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#endif /* _46_lru_cache_h */
