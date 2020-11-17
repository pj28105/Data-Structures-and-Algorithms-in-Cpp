//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
    Linear space and linear time
    Problem link->
    https://practice.geeksforgeeks.org/problems/burning-tree/1/?track=amazon-trees&batchId=192
    
    This idea of this problem is same as->
    https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1/?track=amazon-trees&batchId=192

    This solution has two versions->
    1) First solution is optimized version which computes depth of right and left subtress for each node along with burning time
    in single traversal of tree.

    2) Second solution is less optimized which traverses the each node at most 2 times in worst case.

    Overall complexity of both solution is linear space and time.

    GFG solution=>
    https://www.geeksforgeeks.org/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/
*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


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
int minTime(Node* root, int target) ;

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        cout<<minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

 // } Driver Code Ends


/***********************
 Below is the optimized version
 1st solution
***********************/

 int burn(Node*root,int&ans,int target,unordered_map<Node*,pair<int,int>>&ma){
    if(!root){
        return -1;
    }
    if(!root->left && !root->right){
        ma[root] = {0,0};
        if(root->data == target){
            return 1;
        }
        return -1;
    }
    int lv = burn(root->left,ans,target,ma);
    int rv = burn(root->right,ans,target,ma);
    
    int ldepth = root->left == NULL ? 0: 1 + max(ma[root->left].first,ma[root->left].second); 
    int rdepth = root->right == NULL ? 0: 1 + max(ma[root->right].first,ma[root->right].second); 
    ma[root] = {ldepth,rdepth};
    
    if(lv != -1){
        ans = max(lv + ma[root].second,ans);
        return lv + 1;
    }
    if(rv != -1){
        ans = max(rv + ma[root].first,ans);
        return rv + 1;
    }
    return -1;
}
//User function Template for C++
int minTime(Node* root, int target) {
    unordered_map<Node*,pair<int,int>>ma;
    int ans = 0;
    burn(root,ans,target,ma);
    return ans;
}


/***********************
 Below is the unoptimized version
 2nd solution
***********************/

// void burndown(Node* root,int& ans,int bt){
//     if(!root){
//         return;
//     }
//     ans = max(bt,ans);
//     burndown(root->left,ans,bt + 1);
//     burndown(root->right,ans,bt + 1);
//     return;
// }

// int burn(Node*root,int&ans,int target){
//     if(!root){
//         return -1;
//     }
//     if(root->data == target){
//         return 1;
//     }
//     int lv = burn(root->left,ans,target);
//     int rv = burn(root->right,ans,target);
//     if(lv != -1){
//         ans = max(lv,ans);
//         burndown(root->right,ans,lv + 1);
//         return lv + 1;
//     }
//     if(rv != -1){
//         ans = max(rv,ans);
//         burndown(root->left,ans,rv + 1);
//         return rv + 1;
//     }
//     return -1;
// }



// //User function Template for C++
// int minTime(Node* root, int target) {
//     int ans = 0;
//     burn(root,ans,target);
//     return ans;
// }
