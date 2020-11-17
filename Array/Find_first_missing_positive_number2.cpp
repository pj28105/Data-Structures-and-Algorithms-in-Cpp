/*
    Problem link->
        https://leetcode.com/problems/first-missing-positive/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()){
            return 1;
        }
        int n = nums.size();
        for(int i = 0; i < n; i++){
            long long idx = nums[i] - 1l;
            while(1 <= nums[i] && nums[i] <= n && i != idx && (idx + 1) != nums[idx]){
                swap(nums[i],nums[idx]);
                idx = nums[i] - 1;
            }    
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};