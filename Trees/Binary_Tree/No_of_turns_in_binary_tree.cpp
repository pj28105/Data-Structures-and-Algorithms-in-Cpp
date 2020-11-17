//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

/*
    problem link->
    https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1
    Linear time and space
*/

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int NumberOFTurns(struct Node* root, int first, int second);

 // } Driver Code Ends


//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/
// function should return the number of turns required to go from first node to second node 

Node* findlca(Node* root,int first,int second){
    if(!root)
        return NULL;
    if(root->data == first || root->data == second){
        return root;
    }
    Node* l = findlca(root->left,first,second);
    Node* r = findlca(root->right,first,second);
    if(l && r){
        return root;
    }
    return l == NULL ? r : l;
}

int findTurns(Node* lca,int val,int turns,char prev){
    if(!lca){
        return 0;
    }
    if(lca->data == val){
        return turns;
    }
    int lt = 0;
    if(prev == 'R'){
        lt = findTurns(lca->left,val,turns + 1,'L');
    }else{
        lt = findTurns(lca->left,val,turns,'L');
    }
    int rt = 0;
    if(prev == 'L'){
        rt = findTurns(lca->right,val,turns + 1,'R');
    }else{
        rt = findTurns(lca->right,val,turns,'R');
    }
    return max(lt,rt);
}


int NumberOFTurns(struct Node* root, int first, int second){
    Node* lca = findlca(root,first,second);
    int t2 = findTurns(lca,first,0,'X');
    int t1 = findTurns(lca,second,0,'X');
    if(lca->data != first && lca->data != second){
        return 1 + t2 + t1;
    }
    if((t2 + t1) > 0)
        return (t2 + t1);
    return -1;
}

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        if ((turn = NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends