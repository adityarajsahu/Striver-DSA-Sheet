#include <bits/stdc++.h>
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL)
        return head;
    ListNode *temp=head, *ptr;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    k %= len;
    while(k--){
        temp = head;
        while(temp->next!=NULL){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        temp->next = head;
        head = temp;
    }
    return head;
}