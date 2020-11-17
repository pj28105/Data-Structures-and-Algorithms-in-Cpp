#include <bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/binary-tree-preorder-traversal/
        
    Function is tested on Leetcode!
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> st;
        while(root){
            while(root){
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            while(!st.empty()){
                TreeNode* curr = st.top();
                st.pop();
                if(curr->right){
                    root = curr->right;
                    break;
                }
            }
        }
        return ans;
    }
};