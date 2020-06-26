#include<bits/stdc++.h>
using namespace std;
/*
  Problem link->
        https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1/?track=amazon-linkedlists&batchId=192

    Tested on GFG

    Corner Cases->
     1) Handling leading zeros in the input as well as in the ans
     2) Handle case for borrow carefully
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

Node* subLinkedList(Node* l1, Node* l2);

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
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

int length(Node* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

Node* padding(Node* head,int cnt){
    while(cnt--){
        Node* temp = new Node(0);
        temp->next = head;
        head = temp;
    }
    return head;
}

void subtract(Node* l1,Node* l2,bool& borrow){
    if(!l1){
        return;
    }
    subtract(l1->next,l2->next,borrow);
    if(borrow){
        l1->data--;
        borrow = 0;
    }
    if(l1->data < l2->data){
        borrow = 1;
        l1->data += 10;
    }
    l1->data -= l2->data;
    return;
}

Node* subLinkedList(Node* l1, Node* l2){
    if(!l1 || !l2){
        return l1 == NULL ? l2 : l1;
    }    
    int len1 = length(l1);
    int len2 = length(l2);
    if(len1 != len2){
        if(len1 > len2){
            l2 = padding(l2,len1 - len2);
        }else{
            l1 = padding(l1,len2 - len1);
        }
    }
    Node* c1 = l1,*c2 = l2;
    while(c1){
        if(c1->data > c2->data){
            break;
        }else if(c2->data > c1->data){
            swap(l1,l2);
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    bool borrow = 0;
    subtract(l1,l2,borrow);
    while(l1 && l1->data == 0){
      l1 = l1->next;  
    }
    return l1 == NULL ? new Node(0) : l1;
}