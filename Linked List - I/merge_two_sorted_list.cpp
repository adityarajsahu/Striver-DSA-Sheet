#include <bits/stdc++.h>
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL) {
        return list2;
    }
    
    if(list2 == NULL) {
        return list1;
    }
    
    ListNode* ans = NULL;
    
    if(list1->val <= list2->val) {
        ans = list1;
        ans->next = mergeTwoLists(list1->next, list2);
    } else {
        ans = list2;
        ans->next = mergeTwoLists(list1, list2->next);
    }
    return ans;
}