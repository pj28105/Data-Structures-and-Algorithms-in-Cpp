#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

    1) Time complexity -> O(K*N)
    2) Space Complexity -> O(1) 

    Do check out its heap version and best solution! ,on github!

    Tested on GFG
*/
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

Node * mergeKLists(Node *a[], int n){
     Node* dummy = new Node(-1);
     Node* curr = dummy;
     while(1){
         Node* pick = NULL,**best = NULL;
         for(int i = 0; i < n; i++){
             if(a[i]){
                 if(!pick || pick->data > a[i]->data){
                     pick = a[i];
                     best = &a[i];
                 }
             }
         }
         if(!pick){
             break;
         }
         curr->next = pick;
         curr = pick;
         *best = (*best)->next;
     }
     return dummy->next;
}