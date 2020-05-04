#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1/?track=amazon-trees&batchId=192
    Tested status -> false
    This code is not tested as GFG testcases where too weak!
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};


Node *cloneTree(Node *);
int printInorder(Node* a,Node *b)
{
    if ((a==NULL and b==NULL) or (a->random==NULL and b->random==NULL))
        return 1;




    if(a->random->data == b->random->data and printInorder(a->left,b->left) and printInorder(a->right,b->right))
        return 1;
    return false;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }

     Node *t = cloneTree(root);
      if(t==root)
        cout<<0<<endl;
     else
     cout<<printInorder(root,t);
     cout<<endl;
  }
  return 0;
}



Node* cloneTree(Node* tree);
// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */
void clone1(Node* tree){
    if(!tree){
        return;
    }
    Node* node = new Node(tree->data);
    node->left = tree->left;
    tree->left = node;
    clone1(tree->left->left);
    clone1(tree->right);
    return;
}
void cloneRandom(Node* tree){
    if(!tree){
        return;
    }
    if(tree->random)
        tree->left->random = tree->random->left;
    else
        tree->left->random = NULL;
    cloneRandom(tree->left->left);
    cloneRandom(tree->right);
}
Node* clone2(Node* tree){
    if(!tree)
        return NULL;
        
    Node* curr = tree->left;
    curr->right = tree->right == NULL ? NULL : tree->right->left;
    tree->left = curr->left;
    if(tree->left)
        curr->left = tree->left->left;
    clone2(tree->left);
    clone2(tree->right);
    return curr;
}
void inorder1(Node* tree){
    if(!tree){
        return;
    }
    inorder1(tree->left);
        cout << tree->data << " ";
    inorder1(tree->right);
}
Node* cloneTree(Node* tree){
    clone1(tree);
    cloneRandom(tree);
    Node* root = clone2(tree);
    // inorder1(root); cout << endl;
    // inorder1(tree); cout << endl;
    return root;
}