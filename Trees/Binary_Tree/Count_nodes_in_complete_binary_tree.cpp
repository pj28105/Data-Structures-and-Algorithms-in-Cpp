#include<bits/stdc++.h>
using namespace std;
/*
    Problem link-> 
        https://leetcode.com/problems/count-complete-tree-nodes/
    
    Complexity-> O(logn * logn)
    Tested on Leetcode
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root,int idx,long long depth){
        long long start = 1,end = (1ll << depth);
        while(start != end){
            long long mid = (start + end)/2;
            if(idx > mid){
                start = mid + 1;
                root = root->right;
            }else{
                end = mid;
                root = root->left;
            }
        }
        return root != NULL;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxd = -1;
        TreeNode* curr = root;
        while(curr){
            maxd++;
            curr = curr->left;
        }
        if(maxd == 0){
            return 1;
        }
        long long mask = 0;
        for(long long i = 0; i < maxd; i++){
            mask |= (1ll << i);
        }
        long long st = 1,se = 1 << maxd,extra = 1;
        while(st <= se){
            long long mid = (st + se) >> 1ll;
            if(check(root,mid,maxd)){
                extra = mid;
                st = mid + 1;  
            }else{
                se = mid - 1;
            }
        }
        return mask + extra;
    }
};