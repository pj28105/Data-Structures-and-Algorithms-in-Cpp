/*
    Problem link->
        https://leetcode.com/problems/find-the-duplicate-number/
    
    Alternate solution to floyd cycle detection

    Tested on Leetcode!
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};