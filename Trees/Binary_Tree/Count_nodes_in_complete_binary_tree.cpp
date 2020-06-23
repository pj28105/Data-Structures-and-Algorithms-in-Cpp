#include<bits/stdc++.h>
using namespace std;
/*
    Problem link-> 
        https://leetcode.com/problems/count-complete-tree-nodes/
    
    Complexity-> O(logn * logn)
    Tested on Leetcode
*/
class Solution {
public:
    string convert(int x){
       string bin = "";
       while(x > 0){
          if(x % 2){
              bin += '1';
          }else{
              bin += '0';
          }
          x = x/2;
       }
       reverse(bin.begin(),bin.end());
       return bin;
    }
    bool check(TreeNode* root,string bin,int i){
        if(!root){
            return false;
        }
        if(i == (int)bin.length()){
            return 1;
        }
        if(bin[i] == '1'){
            return check(root->right,bin,i + 1);
        }
        return check(root->left,bin,i + 1);
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int h = 0;
        TreeNode* curr = root;
        while(curr){
            curr = curr->left;
            h++;
        }
        int st = (1 << (h - 1)) ,en = (1 << h) - 1;
        int ans = 0,ref = (1 << (h - 1)) - 1;
        while(st <= en){
            int mid = (st + en) >> 1;
            string bin = convert(mid);
            if(check(root,bin,1)){
                ans = mid - ref;
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }
        ans += ref;
        return ans;
    }
};