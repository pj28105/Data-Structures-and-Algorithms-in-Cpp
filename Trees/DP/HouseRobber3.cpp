#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/house-robber-iii/

    
    Note->  This problem can be solved in two ways! Both solutions are present in file!

    Recently asked in Google interviews!
*/

class Solution {
public:
    unordered_map<TreeNode*,int>dp;
    int solv(TreeNode* root){
        if(!root){
            return 0;
        }
        auto it = dp.find(root);
        if(it != dp.end()){
            return it->second;
        }
        int ans = solv(root->right) + solv(root->left);
        int ans2 = root->val;
        if(root->left){
            ans2 += solv(root->left->right) + solv(root->left->left);
        }
        if(root->right){
            ans2 += solv(root->right->left) + solv(root->right->right);
        }
        dp[root] = max(ans,ans2);
        return dp[root];
    }
    int rob(TreeNode* root) {
        dp.clear();
        return solv(root);
    }
};

class Solution {
public:
    pair<int,int> solv(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> l = solv(root->right);
        pair<int,int> r = solv(root->left);
        int not_rob = max(l.first,l.second) + max(r.first,r.second);
        int rob = root->val + l.first + r.first;
        return {not_rob,rob};
    }
    int rob(TreeNode* root) {
        pair<int,int> ans = solv(root);
        return max(ans.first,ans.second);
    }
};