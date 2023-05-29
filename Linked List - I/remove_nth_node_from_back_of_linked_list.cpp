#include <bits/stdc++.h>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode();
    start->next = head;
    ListNode* ptr1 = start;
    ListNode* ptr2 = start;
    
    for(int i = 0; i < n; i++) {
        ptr2 = ptr2->next;
    }
    
    while(ptr2->next != NULL) {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    
    ListNode* temp = ptr1->next;
    ptr1->next = temp->next;
    delete temp;
    
    return start->next;
}