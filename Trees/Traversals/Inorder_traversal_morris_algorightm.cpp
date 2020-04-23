/*

    This inorder travel is space efficeint and
    based on morris algorithm
    Runtime -> o(n)
    space -> o(1)
    Tested on GFG
*/

void inorder(Node* root){
    if(!root){
        return;
    }
    Node* curr = root;
    while(curr != NULL){
        if(curr->left){
            Node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }
            if(!pred->right){
                pred->right = curr;
                curr = curr->left;
            }else{
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }else{
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    return;
}