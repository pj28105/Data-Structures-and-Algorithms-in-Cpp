#include <bits/stdc++.h> 
using namespace std; 
/*  
    Problem link->
        https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
    
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

Node* pairWiseSwap(Node* head);

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		head = pairWiseSwap(head);
		printList(head);
	}
	return 0; 
}

Node* pairWiseSwap(struct Node* head) {
    if(!head or !head->next){
        return head;
    }
    Node* curr = head,*prev = NULL;
    while(curr && curr->next != NULL){
        if(curr == head){
            Node* nxt = curr->next;
            curr->next = curr->next->next;
            nxt->next = curr;
            head = nxt;
        }else{
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}