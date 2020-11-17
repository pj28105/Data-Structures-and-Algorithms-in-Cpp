#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

/*
    Problem Link->
    https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
    Check Video solution on->
    https://www.youtube.com/watch?v=gcULXE7ViZw

    Code Tested on GFG
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



struct Node* deleteNode(struct Node* root, int key);

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
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
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
}// } Driver Code Ends


/* The structure of a BST Node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; 
*/
Node* getMin(Node* root){
    if(root->left){
        return getMin(root->left);
    }
    return root;
}

Node* getMax(Node* root){
    if(root->right){
        return getMax(root->right);
    }
    return root;
}


Node *deleteNode(Node *root,  int x){
    if(!root){
        return NULL;
    }
    if(root->data < x){
        root->right = deleteNode(root->right,x);
        return root;
    }else if(root->data > x){
        root->left = deleteNode(root->left,x);
        return root;
    }
    // CASE1 -> Leaf
    if(!root->left && !root->right){
        delete root;
        return NULL;
    }
    // CASE2 -> Only one child
    if(!root->left || !root->right){
        Node* node = root->left == NULL ? root->right : root->left;
        delete root;
        return node;
    }
    // CASE 3 -> Two children
    // getMax node from left subtree or getMin node from right subtree
    Node* max_node = getMax(root->left);
    root->data = max_node->data;
    // Delete that node from tree
    root->left = deleteNode(root->left,max_node->data);
    return root;
}