#include <bits/stdc++.h> 
using namespace std; 
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
    
    Tested on GFG
*/
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

Node* addOne(Node *head);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        
        head = addOne(head);
        printList(head); 
    }
    return 0; 
} 

Node* addOne(Node *head) {
    if(!head){
        return head;
    }
    Node* st = NULL,*curr = head,*prev = NULL,*last;
    while(curr){
        if(curr->data == 9){
            if(!st){
                st = curr;
            }
        }else{
            st = NULL;
        }
        if(!st)
            prev = curr;
        last = curr;
        curr = curr->next;
    }
    if(!st){
        last->data += 1;
        return head;
    }
    if(prev){
        prev->data += 1;
        while(st){
            st->data = 0;
            st = st->next;
        }
        return head;
    }
    Node* newHead = new Node(1);
    newHead->next = head;
    while(st){
            st->data = 0;
            st = st->next;
    }
    return newHead;
}