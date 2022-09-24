/*
    Problem link ->
        https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

    Tested on leetcode!
*/

class Solution {
public:
    
    vector<int> result;
    
    void populateDescendantsAtKDistance(TreeNode* root, int currDistance, int k) {
        if(!root){
            return;
        }
        if(currDistance > k){
            return;
        }
        if(currDistance == k){
            result.push_back(root->val);
            return;
        }
        populateDescendantsAtKDistance(root->left, currDistance + 1, k);
        populateDescendantsAtKDistance(root->right, currDistance + 1, k);
    }
    
    int distanceFromChild(TreeNode* root, TreeNode* childNode, int k) {
        if(!root){
            return -1;
        }
        if(root->val == childNode->val){
            populateDescendantsAtKDistance(root, 0, k);
            return 0;
        }
        int leftDistanceFromChild = distanceFromChild(root->left, childNode, k);
        int rightDistanceFromChild = distanceFromChild(root->right, childNode, k);
        if(leftDistanceFromChild != -1){
            if((leftDistanceFromChild + 1) == k) {
                result.push_back(root->val);
            }else{
                populateDescendantsAtKDistance(root->right, leftDistanceFromChild + 2, k);    
            }
            return leftDistanceFromChild + 1;
            
        }else if(rightDistanceFromChild != -1){
            if((rightDistanceFromChild + 1) == k){
                result.push_back(root->val);
            }else{
                populateDescendantsAtKDistance(root->left, rightDistanceFromChild + 2, k);
            }
            return rightDistanceFromChild + 1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        result.clear();
        distanceFromChild(root, target, k); 
        return result;
    }
};