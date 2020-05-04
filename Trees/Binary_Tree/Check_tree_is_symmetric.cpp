#include<bits/stdc++.h>
using namespace std;

/*

     Tree Building funcs are from GFG
     Check last function
     Function is tested on GFG
     Symmetric tree is tree in which right subtree is mirror image of left subtree
*/

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
bool isSymmetric(struct Node* root);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        if(isSymmetric(root))
            cout<<"True"<<endl;
        else 
            cout<<"False"<<endl;
  }
  return 0;
}
// } Driver Code Ends
/*
Structure of the node of the tree is as
struct Node
{
	int data;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not
bool isSymmetric(struct Node* root)
{
    if(!root){
        return true;
    }
    stack<Node*> st;
    st.push(root->left);
    st.push(root->right);
    while(!st.empty()){
        Node* l = st.top();
        st.pop();
        Node* r = st.top();
        st.pop();
        if(!l && !r){
            continue;
        }
        if(!l || !r){
            return false;
        }
        if(l->data == r->data){
            st.push(l->left);
            st.push(r->right);
            st.push(l->right);
            st.push(r->left);
        }else{
            return false;
        }
    }
    return true;
}