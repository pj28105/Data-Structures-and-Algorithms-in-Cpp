#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
    https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1/?track=amazon-trees&batchId=192

    Insertion -> O(Logn)
    Pls remember the height update order in rotations z will be updated first then y.
    This bug cost me hours and 5 WA.
*/


struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    height = 1;
	}
};

int heigh(struct Node* Node)
{
   /* base case tree is empty */
   if(Node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(heigh(Node->left), heigh(Node->right));
} 

bool isBalanced(struct Node *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */ 
 
   /* If tree is empty then return true */
   if(root == NULL)
    return 1; 
 
   /* Get the height of left and right sub trees */
   lh = heigh(root->left);
   rh = heigh(root->right);
 
   if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
 
   /* If we reach here then tree is not height-balanced */
   return 0;
}
 
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
 
/* returns maximum of two integers */
   
 
/*  The function Compute the "height" of a tree. Height is the
    number of Nodes along the longest path from the root Node
    down to the farthest leaf Node.*/


int _B_(Node *root)
{
    if(root==NULL)
        return 0;
    int lH = _B_(root->left);
    if(lH==-1)return -1;
    int rH = _B_(root->right);
    if(rH==-1)
        return -1;

    if(abs(lH-rH)>1)
        return -1;
    return max(lH,rH)+1;
}

bool _B(Node *root)
{
    if(_B_(root)==-1)
        return false;
    else 
        return true;
}

bool I_(Node* root)
{
    static struct Node *prev = NULL;
     
    if (root)
    {
        if (!I_(root->left))
          return false;
 
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return I_(root->right);
    }
 
    return true;
}
Node* insertToAVL(Node* Node, int data);

vector<int> z;
void inorder(Node *root)
{
//	z.clear();
	if(root==NULL)
	return;
	{
		inorder(root->left);
		z.push_back(root->data);
		inorder(root->right);
	}
}


/* Drier program to test above function*/
int main()
{



int t;
cin>>t;
while(t--)
{
    int q;
    cin>>q;
    Node *root = NULL;
    bool f= true;
    vector<int> a;
    while(q--)
    {
        int k;
        cin>>k;
        a.push_back(k);
        root = insertToAVL(root,k);

        if(!isBalanced(root)){
            f=false;
            break;
        }
    }
    
    z.clear();
    
    inorder(root);
    
    set<int> s(a.begin(),a.end());
   	vector<int>zz(s.begin(),s.end());
    if(z.size()!=zz.size())
    f=false;
    else{
    for(int i=0;i<z.size();i++)
    {
    	if(z[i]!=zz[i])
    	f=false;
    }
    }

    if(f)
        cout<<1<<endl;
    else 
        cout<<0<<endl;
}

return 0;
}
// } Driver Code Ends


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

/*You are required to complete this method */
int height(Node* root){
    if(!root){
        return 0;
    }
    return root->height;
}
Node* rightRotate(Node* z){
    Node* y = z->left;
    Node* subtree = y->right;
    y->right = z;
    z->left = subtree;
    z->height = 1 + max(height(z->left),height(z->right));
    y->height = 1 + max(height(y->left),height(y->right));
    return y;
}


Node* leftRotate(Node* z){
    Node* y = z->right;
    Node* subtree = y->left;
    y->left = z;
    z->right = subtree;
    z->height = 1 + max(height(z->left),height(z->right));
    y->height = 1 + max(height(y->left),height(y->right));
    return y;
}

Node* insertToAVL( Node* node, int data){
   if(!node){
        return new Node(data);
    }
    if(node->data < data){
        node->right = insertToAVL(node->right,data);
    }else if(node->data > data){
        node->left = insertToAVL(node->left,data);
    }else{
        return node;
    }
    node->height = 1 + max(height(node->right),height(node->left));
    // Calculate balancing factor
    int bf = height(node->left) - height(node->right);
    // LL or LR 
    if(bf > 1 && node->left->data > data){
        return rightRotate(node);
    }
    if(bf > 1 && node->left->data < data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(bf < -1 && node->right->data < data){
            return leftRotate(node);
    }
    if(bf < -1 && node->right->data > data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}