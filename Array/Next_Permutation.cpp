/*
    Problem link->
        https://leetcode.com/problems/next-permutation/
    
    Tested on Leetcode!
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty() || (int)nums.size() == 1){
            return;
        }
        int in = INT_MAX,n = nums.size();
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                in = i;
                break;
            }
        }
        if(in == INT_MAX){
            reverse(nums.begin(),nums.end());
            return;
        }
        int swap_in;
        for(int i = n - 1; i > in; i--){
            if(nums[i] > nums[in]){
                swap_in = i;
                break;
            }
        }
        swap(nums[swap_in],nums[in]);
        reverse(nums.begin() + in + 1,nums.end());
    }
};