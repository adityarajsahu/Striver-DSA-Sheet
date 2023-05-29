#include <bits/stdc++.h>
using namespace std;

ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }        

    ListNode* ans = reverseList(head->next);
    head->next->next = head->next;
    head->next = NULL;

    return ans;
}