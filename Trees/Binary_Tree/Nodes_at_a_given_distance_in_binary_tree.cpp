#include<bits/stdc++.h>
using namespace std;

/*
    Problem Link->
    https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1/?track=amazon-trees&batchId=192
    Leetcode Link->
    https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
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

void printkdistanceNodeDown(Node *root, int k);

int printkdistanceNode(Node* root, int target , int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        printkdistanceNode(head, target, k);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printkdistanceNodeDown(Node *root, int k,int curr){
    if(!root || curr > k){
        return;
    }
    if(k == curr){
        cout << root->data << " ";
        return;
    }
    printkdistanceNodeDown(root->left,k,curr + 1);
    printkdistanceNodeDown(root->right,k,curr + 1);
}

/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
int printkdistanceNode(Node* root, int target , int k){
    if(!root){
        return -1;
    }
    if(root->data == target){
        printkdistanceNodeDown(root->left,k,1);
        printkdistanceNodeDown(root->right,k,1);
        return 1;
    }
    int lv = printkdistanceNode(root->left,target,k);
    int rv = printkdistanceNode(root->right,target,k);
    if(lv != -1){
        if(lv == k){
            cout << root->data << " ";
        }else{
            printkdistanceNodeDown(root->right,k - lv,1);
        }
        return lv + 1;
    }
    if(rv != -1){
        if(rv == k){
            cout << root->data << " ";
        }else{
            printkdistanceNodeDown(root->left,k - rv,1);
        }
        return rv + 1;
    }
    return -1;
}