#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
    
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

void backRoute(Node* &head,unordered_map<Node*,Node*>&ma){
    Node* prev = NULL;
    while(head->next){
        ma[head] = prev;
        prev = head;
        head = head->next;
    }
    ma[head] = prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second){
    if(!first){
        return second; 
    }
    if(!second){
        return first;
    }
    int carry = 0;
    unordered_map<Node*,Node*> f,s;
    backRoute(first,f);
    backRoute(second,s);
    Node *curr = NULL;
    while(first && second){
        carry += first->data + second->data;
        first->data = carry % 10;
        carry = carry/10;
        if(!curr){
            curr = first;
        }else{
            first->next = curr;
            curr = first;
        }
        first = f[first];
        second = s[second];
    }
    while(first){
        carry += first->data;
        first->data = carry % 10;
        carry = carry/10;
        first->next = curr;
        curr = first;
        first = f[first];
    }
    while(second){
        carry += second->data;
        second->data = carry % 10;
        carry = carry/10;
        second->next = curr;
        curr = second;
        second = s[second];
    }
    if(carry){
        Node* temp = new Node(carry);
        temp->next = curr;
        curr = temp;
    }
    return curr;
}