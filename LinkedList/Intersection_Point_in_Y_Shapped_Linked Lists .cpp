#include<iostream>
#include<stdio.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

    Note->
        This problem can also be solved by two pointers check github!
        
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

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   
int getLength(Node* head){
    int len = 0;
    while(head){
        len ++;
        head = head->next;
    }
    return len;
}

int intersectPoint(Node* l1, Node* l2){
    if(!l1 or !l2){
        return -1;
    }
    int len1 = getLength(l1),len2 = getLength(l2);
    int diff = len1 - len2;
    if(diff > 0){
        while(l1 && diff--){
            l1 = l1->next;
        }
    }else if(diff < 0){
        diff *= -1;
        while(l2 && diff--){
            l2 = l2->next;
        }
    }
    while(l1 && l2){
        if(l1 == l2){
            return l1->data;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return -1;
}