#include <bits/stdc++.h>
using namespace std;

bool hasCycle(ListNode *head) {
    set<ListNode*> s;
    ListNode* ptr = head;
    
    while(ptr) {
        if(s.count(ptr)) {
            return true;
        }
        s.insert(ptr);
        ptr = ptr->next;
    }
    return false;
}