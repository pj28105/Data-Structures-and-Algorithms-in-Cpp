#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
    
    Tested on GFG
*/
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}

int getNthFromLast(Node *head, int n){
     int len = 1;
     Node* mv = head;
     while(mv && len < n){
         len++;
         mv = mv->next;
     }
     if(!mv){
         return -1;
     }
     Node* curr = head;
     while(mv->next){
         mv = mv->next;
         curr = curr->next;
     }
     return curr->data;
}