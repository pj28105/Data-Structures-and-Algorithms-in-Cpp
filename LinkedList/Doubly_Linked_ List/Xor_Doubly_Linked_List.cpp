#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/xor-linked-list/1

    Tested on GFG
*/
struct Node
{
	int data;
	struct Node* npx; 
	
	Node(int x){
	    data = x;
	    npx = NULL;
	}
};

struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void insert(struct Node **head_ref, int data);

void printList (struct Node *head);

// Driver program to test above functions
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *head = NULL;
        int n, tmp;
        cin>>n;
        while(n--)
        {
            cin>>tmp;
            insert(&head, tmp);
        }
        printList (head);
        cout<<"\n";
    }
	return (0);
}
// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
	int data;
	struct Node* npx; 
	
	Node(int x){
	    data = x;
	    npx = NULL;
	}
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers 
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/


// function should insert the data to the front of the list
void insert(struct Node **head, int data){
	if(*head == NULL){
	   *head = new Node(data);
	   (*head)->npx = NULL;
	    return;
	}
	Node* temp = new Node(data);
	temp->npx = *head;
	(*head)->npx =  XOR((*head)->npx,temp);
	*head = temp;
	return;
}

// function should prints the contents of doubly linked list
// first in forward direction and then in backward direction
// you should print a next line after printing in forward direction
void printList (struct Node *head){
	if(!head){
	    return;
	}
	Node* curr = head,*prev = NULL;
	while(1){
	    cout << curr->data << " ";
	    Node* temp = curr;
	    curr = XOR(curr->npx,prev);
	    prev = temp;
	    if(!curr){
	        break;
	    }
	}
	cout << endl;
	curr = prev;
	prev = NULL;
	while(1){
	    cout << curr->data << " ";
	    Node* temp = curr;
	    curr = XOR(curr->npx,prev);
	    if(!curr){
	        break;
	    }
	    prev = temp;
	}
	return;
}
