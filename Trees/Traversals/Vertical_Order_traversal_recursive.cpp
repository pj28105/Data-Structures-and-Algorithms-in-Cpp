#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/?track=amazon-trees&batchId=192
    
    Prefer these questions to do iteratively with level order traversal only!
    This question also teaches that use always stable_sort instead of sort in c++
    as sort may not be stable all the time but stable sort ensures stability in sorting.
    If you are doing this question recursively sort the map of vector with stable_sort in decrasing order of lvl 
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

void verticalOrder(Node *root);

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
    	Node* root = buildTree(s);
    	
    	verticalOrder(root);
        cout << endl;
    }
	return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// root: root node of the tree
void solv(Node* root,map<int,vector<pair<int,int>>>& ma,int hd,int lvl){
    if(!root){
        return;
    }
    ma[hd].push_back({root->data,lvl});
    solv(root->left,ma,hd - 1,lvl+1);
    solv(root->right,ma,hd + 1,lvl+1);
    return;
}
void verticalOrder(Node *root){
    if(!root){
        return;
    }
    map<int,vector<pair<int,int>>> ma;
    solv(root,ma,0,0);

    // Note to print the vector in same loop use &i
    for(auto i: ma){
        stable_sort(ma[i.first].begin(),ma[i.first].end(),[](pair<int,int>a,pair<int,int>b)->bool{
            return a.second < b.second; 
        });
    }
    for(auto i : ma){
        for(auto j : i.second){
            cout << j.first << " ";
        }
    }
}