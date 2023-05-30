#include <bits/stdc++.h>
using namespace std;

ListNode* reverse(ListNode* ptr) {
    ListNode* prev = NULL;
    ListNode* nex = NULL;
    while(ptr != NULL) {
        nex = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nex;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return true;
    }
        
    ListNode* slow = head;
    ListNode* fast = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
    ListNode* ptr = head;
        
    while(slow != NULL) {
        if(ptr->val != slow->val) {
            return false;
        }
        ptr = ptr->next;
        slow = slow->next;
    }
    return true;
}