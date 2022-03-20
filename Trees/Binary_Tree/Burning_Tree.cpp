/*

    Problem link: https://practice.geeksforgeeks.org/problems/burning-tree/1/?track=amazon-trees&batchId=192
    Tested: True on GFG
    Note: This solution works not only for leaf but for every node.
*/
class Solution {
  public:
    
    int updateNodeHeight(Node* root, unordered_map<Node*, int>& heightMap){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            heightMap[root] = 1;
            return 1;
        }
        heightMap[root] = 1 + max(updateNodeHeight(root->left, heightMap) , 
                                updateNodeHeight(root->right, heightMap));
        return heightMap[root];
    }
    
    int burn(Node* root, int target, int& result, unordered_map<Node*, int>& heightMap){
        if(!root){
            return -1;
        }
        if(root->data == target){
            result = heightMap[root] - 1;
            return 0;
        }
        int leftFireReachTime = burn(root->left, target, result, heightMap);
        int rightFireReachTime = burn(root->right, target, result, heightMap);
        if(leftFireReachTime != -1){
            int rightSubTreeHeight = (root->right != NULL) ? heightMap[root->right] : 0;
            result = max(result, rightSubTreeHeight + leftFireReachTime + 1);
            return leftFireReachTime + 1;
        }
        if(rightFireReachTime != -1){
            int leftSubTreeHeight = (root->left != NULL) ? heightMap[root->left] : 0;
            result = max(result, leftSubTreeHeight + rightFireReachTime + 1);
            return rightFireReachTime + 1;
        }
        return -1;
    }
  
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, int> heightMap;
        updateNodeHeight(root, heightMap);
        if(root->data == target){
            return heightMap[root] - 1;   
        }
        int result = 0;
        burn(root, target, result, heightMap);
        return result;
    }
};
