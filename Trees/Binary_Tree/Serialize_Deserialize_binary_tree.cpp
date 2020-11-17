#include <bits/stdc++.h>

using namespace std;


/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

    Serialization can be improved further by marking all leaf nodes with -2 and all internodes with
    only one children with -1

    See editorial and my amazon spreadsheet for further exp.
*/

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root,vector<int> &a){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        a.push_back(curr == NULL ? -1 : curr->data);
        if(curr){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return;
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &a){
  if(a.empty() || a[0] == -1){
      return NULL;
  }
  Node* root = new Node(a[0]);
  queue<Node*> q;
  q.push(root);
  int in = 1;
  while(!q.empty()){
      Node* curr = q.front();
      q.pop();
      if(a[in] != -1){
          curr->left = new Node(a[in]);
      }
      in++;
      if(a[in] != -1){
          curr->right = new Node(a[in]);
      }
      in++;
      if(curr->left){
          q.push(curr->left);
      }
      if(curr->right){
          q.push(curr->right);
      }
  }
  return root;
}

// { Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        vector<int> A;
        serialize(root, A);

        Node *getRoot = deSerialize(A);
        inorder(getRoot);
        cout << "\n";

    }


    return 0;
}  // } Driver Code Ends