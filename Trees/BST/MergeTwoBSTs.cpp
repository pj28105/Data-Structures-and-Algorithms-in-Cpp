#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000


/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

    This solution contains inorder traversal of two tress simultaneously such that the elements
    will be printed in sorted form. I have got 3 WA because of one silly mistake. Whenever any one
    of the tree got exhausted my two loops below that were wrong i was not pushing the right child to
    stack due to this inorder traversal of remainging tree will be incomplete.

    i have that statement with <Dont't miss this>

    Tested on leetcode and GFG
*/

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> merge(Node *root1, Node *root2);

// Function to Build Tree
Node *buildTree(string str)
{
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
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);

        vector<int> vec = merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        ///cout<<"~"<<endl;
    }
    return 0;
} // } Driver Code Ends

/* The structure of Node is
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/

/*You are required to complete below method */

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> st1, st2;
    Node *curr1 = root1, *curr2 = root2;
    while (1)
    {
        if (curr1 || curr2)
        {
            if (curr1)
            {
                st1.push(curr1);
                curr1 = curr1->left;
            }
            if (curr2)
            {
                st2.push(curr2);
                curr2 = curr2->left;
            }
        }
        else
        {
            if (st1.empty() || st2.empty())
            {
                break;
            }
            curr1 = st1.top();
            curr2 = st2.top();
            if (curr1->data < curr2->data)
            {
                ans.push_back(curr1->data);
                st1.pop();
                curr1 = curr1->right;
                curr2 = NULL;
            }
            else
            {
                ans.push_back(curr2->data);
                st2.pop();
                curr2 = curr2->right;
                curr1 = NULL;
            }
        }
    }
    while (!st1.empty())
    {
        while (curr1)
        {
            st1.push(curr1);
            curr1 = curr1->left;
        }
        while (!st1.empty())
        {
            curr1 = st1.top();
            st1.pop();
            ans.push_back(curr1->data);
            if (curr1->right)
            {
                /* <Dont't miss this> */
                curr1 = curr1->right;
                st1.push(curr1);
                curr1 = curr1->left;
                /* <Dont't miss this> */
                break;
            }
        }
    }
    while (!st2.empty())
    {
        while (curr2)
        {
            st2.push(curr2);
            curr2 = curr2->left;
        }
        while (!st2.empty())
        {
            curr2 = st2.top();
            st2.pop();
            ans.push_back(curr2->data);
            if (curr2->right)
            {
                /* <Dont't miss this> */
                curr2 = curr2->right;
                st2.push(curr2);
                curr2 = curr2->left;
                /* <Dont't miss this> */
                break;
            }
        }
    }
    return ans;
}