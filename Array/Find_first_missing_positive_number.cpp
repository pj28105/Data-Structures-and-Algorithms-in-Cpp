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
        int inf = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0){
                nums[i] = inf;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) <= nums.size()){
                if(nums[abs(nums[i]) - 1] > 0)
                    nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};