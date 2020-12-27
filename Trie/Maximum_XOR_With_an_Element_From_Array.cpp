/*
    Problem link->
        https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

    Tested on Leetcode!
*/
class Node{
public:
    Node* left,*right;
    Node(){
        left = right = NULL;
    }
    void insert(int num){
        Node* root = this;
        for(int i = 30; i >= 0; i--){
            int mask = 1 << i;
            if(mask & num){
                if(!root->right){
                    root->right = new Node();
                }
                root = root->right;
            }else{
                if(!root->left){
                    root->left = new Node();
                }
                root = root->left;
            }
        }
        return;
    }
    int query(int num){
        int result = 0;
        Node* root = this;
        if(!root->left && !root->right){
            return -1;
        }
        for(int i = 30; i >= 0; i--){
            int mask = 1 << i;
            if(mask & num){
                if(root->left){
                    root = root->left;
                }else{
                    result |= mask;
                    root = root->right;
                }
            }else{
                if(root->right){
                    root = root->right;
                    result |= mask;
                }else{
                    root = root->left;
                }
            }
        }
        return (result ^ num);
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        int index = 0,qindex = 0,n = nums.size();
        vector<int>ans(q.size());
        sort(nums.begin(),nums.end());
        for(int i = 0; i < q.size(); i++){
            q[i].push_back(i);
        }
        sort(q.begin(),q.end(),[](vector<int>&a,vector<int>&b)->bool{
           return  a[1] < b[1];
        });
        Node* root = new Node();
        while(qindex < q.size()){
            while((index < n) && nums[index] <= q[qindex][1]){
                root->insert(nums[index]);
                index++;
            }
            ans[q[qindex][2]] = root->query(q[qindex][0]);
            qindex++;
        }
        return ans;
    }
};