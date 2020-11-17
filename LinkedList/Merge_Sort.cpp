#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

    1) Corner case while calculating middle of linked list!
    2) Always split lists by mid and previous(mid) otherwise you will end up in infinite recursion!
    
    Tested on GFG
*/
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* merge(Node* l1,Node* l2){
    if(!l1 or !l2){
        return l1 == NULL ? l2 : l1;
    }
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(l1 && l2){
        if(l1->data <= l2->data){
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
        }else{
            curr->next = l2;
            curr = l2;
            l2 = l2->next;
        }
    }
    if(!l1){
        curr->next = l2;
        curr = l2;
    }else{
        curr->next = l1;
        curr = l1;
    }
    return dummy->next;
}

Node* mergeSort(Node* head) {
    
    if(!head or !head->next){
        return head;
    }
    Node* slow = head,*fast = head,*prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    head = mergeSort(head);
    slow = mergeSort(slow);
    head = merge(head,slow);
    return head;
}


void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}