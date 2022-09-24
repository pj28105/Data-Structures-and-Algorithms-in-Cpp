/*
    Problem link-> https://leetcode.com/problems/binary-tree-postorder-traversal/

    Tested on leetcode!

    Steps:
        1) Do traversal in (root->right->left) fashion (Refer morris pre order traveral)
        2) Reverse result in the end to (left->right->root) 
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> result;
        while(root){
            if(root->right){
                TreeNode* curr = root->right;
                while(curr->left && curr->left != root){
                    curr = curr->left;
                }
                if(curr->left == root){
                    curr->left = NULL;
                    root = root->left;
                }else{
                    curr->left = root;
                    result.push_back(root->val);
                    root = root->right;
                }
            }else{
                result.push_back(root->val);
                root = root->left;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
