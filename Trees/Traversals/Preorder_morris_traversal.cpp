#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/binary-tree-preorder-traversal/
    
    Tested on Leetcode!
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode *curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }
                if(!curr->right){
                    curr->right = root;
                    ans.push_back(root->val);
                    root = root->left;
                }else{
                    curr->right = NULL;
                    root = root->right;
                }
            }else{
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};