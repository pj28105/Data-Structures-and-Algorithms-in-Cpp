/*
    Problem link->
        https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
        
    Tested on Leetcode!
*/
class Solution {
public:
    TreeNode* lca(TreeNode* root,TreeNode* l,TreeNode* r){
        if(!root){
            return NULL;
        }
        if(root == l || root == r){
            return root;
        }
        TreeNode* lnode = lca(root->left,l,r);
        TreeNode* rnode = lca(root->right,l,r);
        if(lnode && rnode){
            return root;
        }
        return lnode == NULL ? rnode : lnode;
    }
    void findDeepest(TreeNode* root,bool dir,int currDepth,int& maxDepth,TreeNode* &result){
        if(!root){
            return;
        }
        if(maxDepth < currDepth){
            maxDepth = currDepth;
            result = root;
        }
        if(!dir){
            findDeepest(root->left,dir,currDepth + 1,maxDepth,result);
            findDeepest(root->right,dir,currDepth + 1,maxDepth,result);
            return;
        }
        findDeepest(root->right,dir,currDepth + 1,maxDepth,result);
        findDeepest(root->left,dir,currDepth + 1,maxDepth,result);    
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root){
            return NULL;
        }
        int maxDepth = 0;
        TreeNode* l,*r;
        findDeepest(root,0,1,maxDepth,l);
        maxDepth = 0;
        findDeepest(root,1,1,maxDepth,r);
        if(l == r){
            return l;
        }
        return lca(root,l,r);
    }
};