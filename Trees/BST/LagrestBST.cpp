#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/largest-bst/1

*/

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}



int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};*/

/*You are required to complete this method */

pair<int,pair<int,int>> solv(Node* root,int& ans){
    if(!root->right && !root->left){
        ans = max(1,ans);
        return {1,{root->data,root->data}};
    }
    pair<int,pair<int,int>> lv = {0,{INT_MAX,-1}};
    pair<int,pair<int,int>> rv = {0,{-1,INT_MIN}};
    
    if(root->left)
        lv = solv(root->left,ans);
    if(root->right)
        rv = solv(root->right,ans);
    
    if((!root->left || root->data > lv.second.second) && 
        (!root->right || root->data < rv.second.first) && lv.first != -1 && rv.first != -1){
            int total = 1 + rv.first + lv.first;
            ans = max(total,ans);
            return { total,{ min(lv.second.first,root->data),max(root->data,rv.second.second) } };
        }
    return {-1,{0,0}};
}


int largestBst(Node *root)
{
	int ans = 0;
	solv(root,ans);
	return ans;
}