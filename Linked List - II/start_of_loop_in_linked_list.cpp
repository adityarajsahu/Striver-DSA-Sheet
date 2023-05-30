#include <bits/stdc++.h>
using namespace std;

ListNode *detectCycle(ListNode *head) {
    ListNode* ptr = head;
    set<ListNode*> s;
    
    while(ptr) {
        if(s.count(ptr)) {
            return ptr;
        }
        s.insert(ptr);
        ptr = ptr->next;
    }
    return NULL;
}