#include <bits/stdc++.h>

using namespace std;

/*
    Problem Link->
    https://practice.geeksforgeeks.org/problems/check-if-subtree/1/?track=amazon-trees&batchId=192
    <<< Linear Space and Time  if tree is of characters i dont know complexity for kmp with numbers >>>
    Code is Tested on Leetcode and GFG
    Pls note-> in this code i have considered a empty tree is subtree of every tree
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/* A binary tree node

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

/*you are required to
complete this function */
void  inorder(Node* t,vector<int>& t_inorder){
    if(!t){
        t_inorder.push_back(INT_MIN);
        return;
    }
    inorder(t->left,t_inorder);
    t_inorder.push_back(t->data);
    inorder(t->right,t_inorder);
}

void preorder(Node* t,vector<int>& t_preorder){
    if(!t){
        t_preorder.push_back(INT_MIN);
        return;
    }
    t_preorder.push_back(t->data);
    preorder(t->left,t_preorder);
    preorder(t->right,t_preorder);
}

bool kmp(vector<int>& t,vector<int>& p){
    int lps[p.size()] = {0};
    int i = 1,j = 0;
    while(i < p.size()){
        if(p[i] == p[j]){
            lps[i] = ++j;
            i++;
        }else{
            if(j == 0){
                lps[i] = 0;
                i++;
            }else{
                j = lps[j - 1];
            }
        }
    }
    i = 0,j = 0;
    while(i < t.size()){
        if(t[i] == p[j]){
            i++;
            j++;
        }else{
            if(j == 0){
                i++;
            }else{
                j = lps[j - 1];
            }
        }
        if(j == p.size()){
            return 1;
        }
    }
    return 0;
}

bool isSubTree(Node* t, Node* s) {
    if(!s){
        return 1;
    }
    if(!t){
        return 0;
    }
    vector<int> t_inorder,t_preorder,s_inorder,s_preorder;
    inorder(t,t_inorder);
    preorder(t,t_preorder);
    inorder(s,s_inorder);
    preorder(s,s_preorder);
    return kmp(t_preorder,s_preorder) && kmp(t_inorder,s_inorder);
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Node *rootS = buildTree(strS);
        cout << isSubTree(rootT, rootS) << "\n";

    }


    return 0;
}  // } Driver Code Ends