#include <bits/stdc++.h>
using namespace std;

ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    if (fast == NULL) {
        return head;
    }

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}