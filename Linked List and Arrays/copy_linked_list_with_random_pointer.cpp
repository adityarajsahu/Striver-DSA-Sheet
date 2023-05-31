#include <bits/stdc++.h>
using namespace std;

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;
    Node* ptr = head;
    
    while(ptr) {
        Node* newNode = new Node(ptr->val);
        m[ptr] = newNode;
        ptr = ptr->next;
    }
    
    ptr = head;
    while(ptr) {
        Node* temp = m[ptr];
        temp->next = (ptr->next != NULL) ? m[ptr->next] : NULL;
        temp->random = (ptr->random != NULL) ? m[ptr->random] : NULL;
        ptr = ptr->next;
    }
    return m[head];
}