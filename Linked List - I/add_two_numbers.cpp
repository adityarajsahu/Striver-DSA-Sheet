#include <bits/stdc++.h>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* answer = new ListNode();
    ListNode* temp = answer;
    int carry = 0;
    
    while(l1 != NULL || l2 != NULL || carry) {
        int sum = 0;
        
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);
        temp->next = newNode;
        temp = temp->next;
    }
    return answer->next;
}