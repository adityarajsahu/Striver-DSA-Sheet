#include <bits/stdc++.h>
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> s;
    ListNode* ptr = headA;
    
    while(ptr) {
        s.insert(ptr);
        ptr = ptr->next;
    }
    
    ptr = headB;
    while(ptr) {
        if(s.count(ptr)) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}