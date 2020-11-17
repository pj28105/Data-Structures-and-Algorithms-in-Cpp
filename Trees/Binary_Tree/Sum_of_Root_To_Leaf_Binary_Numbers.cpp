/*
    Problem link->
        https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        long long ans = 0,curr = 0;
        while(root){
            if(root->left){
                TreeNode* pre = root->left;
                int steps = 1;
                while(pre->right && pre->right != root){
                    pre = pre->right;
                    steps++;
                }
                if(pre->right == NULL){
                    curr = 2*curr + root->val;
                    pre->right = root;
                    root = root->left;
                }else{
                    if(!pre->left){
                        ans += curr;
                    }
                    for(int i = 0; i < steps; i++){
                        curr = curr/2;
                    }
                    pre->right = NULL;
                    root = root->right;
                }
            }else{
                curr = curr*2 + root->val;   
                if(!root->right){
                    ans += curr;
                }
                root = root->right;
            }
        }
        return ans;
    }
};