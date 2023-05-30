#include <bits/stdc++.h>
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;

    int nodeCount = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        nodeCount++;
        temp = temp->next;
    }

    if (nodeCount < k) {
        return head;
    }

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}