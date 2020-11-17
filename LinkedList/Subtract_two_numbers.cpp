#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1/?track=amazon-linkedlists&batchId=192

    Tested on GFG

    Corner Cases->
     1) Handling leading zeros in the input as well as in the ans
     2) Handle case for borrow carefully

     Implementation of this problem can be further simplified!
        1) Make linkedlist of equal length by padding zeros to shorter one
        2) Then select bigger of them
        3) Then finally subtract!
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

Node* reverse(Node* head){
    Node* rev = NULL;
    while(head){
        Node* nxt = head->next;
        head->next = rev;
        rev = head;
        head = nxt;
    }
    return rev;
}

Node* subLinkedList(Node* l1, Node* l2){
    while(l1 &&l1->data == 0){
        l1 = l1->next;
    }
    while(l2 &&l2->data == 0){
        l2 = l2->next;
    }
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    int len1 = length(l1);
    int len2 = length(l2);
    if(len1 < len2){
        swap(l1,l2);
    }else if(len1 == len2){
        Node* c1 = l1,*c2 = l2;
        while(c1){
            if(c1->data < c2->data){
                swap(l1,l2);
                break;
            }else if(c1->data > c2->data){
                break;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
    }
    l1 = reverse(l1);
    l2 = reverse(l2);
    bool borrow = 0;
    Node* ans = NULL,*temp = NULL;
    while(l1 && l2){
        if(borrow){
            l1->data--;
        }
        if(l1->data < l2->data){
            l1->data = 10 + l1->data - l2->data;
            borrow = 1;
        }else{
            if(borrow){
                borrow = 0;
            }
            l1->data -= l2->data; 
        }
        temp = l1->next;
        l1->next = ans;
        ans = l1;
        l1 = temp;
        l2 = l2->next;
    }
    while(l1){
        if(borrow){
            if(l1->data == 0){
                l1->data = 9;
            }else{
                l1->data--;
                borrow = 0;
            }
        }
        temp = l1->next;
        l1->next = ans;
        ans = l1;
        l1 = temp;
    }
    while(ans && ans->data == 0){
        ans = ans->next;
    }
    return ans == NULL ? new Node(0) : ans;
}