#include <bits/stdc++.h>

using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
    
    Tested on GFG
*/

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

struct Node* segregate(struct Node *head);

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
}

Node* segregate(Node *head) {
    if(!head){
        return head;
    }
    Node* oh = new Node(1);
    Node* th = new Node(2);
    Node* zh = new Node(0);
    Node* o = oh,*z = zh,*t = th,*curr = head;
    while(curr){
        if(curr->data == 0){
            z->next = curr;
            z = curr;
        }else if(curr->data == 1){
            o->next = curr;
            o = curr;
        }else{
            t->next = curr;
            t = curr;
        }
        Node* nxt = curr->next;
        curr->next = NULL;
        curr = nxt;
    }
    o->next = th->next;
    z->next = oh->next;
    /*
        Don't forget to delete dummy nodes!
    */
    return zh->next;
}
