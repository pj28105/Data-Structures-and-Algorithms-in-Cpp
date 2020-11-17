/*
    Problem link->
        https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
    
    Tested on Leetcode!
*/
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        TreeNode* curr = NULL;
        while(!st1.empty() || !st2.empty() || root1 || root2){
            while(root1){
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                st2.push(root2);
                root2 = root2->left;
            }   
            if(st2.empty() || (!st1.empty() && st1.top()->val <= st2.top()->val)){
                curr = st1.top();
                st1.pop();
                ans.push_back(curr->val);
                if(curr->right){
                    root1 = curr->right;
                }
            }else{
                curr = st2.top();
                st2.pop();
                ans.push_back(curr->val);
                if(curr->right){
                    root2 = curr->right;
                }
            }
        }
        return ans;
    }
};