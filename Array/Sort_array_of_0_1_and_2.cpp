/*
    Problem link->
        https://leetcode.com/problems/sort-colors/
    
    Tested on Leetcode!
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }
        int low = 0,high = nums.size() - 1,mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        return;
    }
};