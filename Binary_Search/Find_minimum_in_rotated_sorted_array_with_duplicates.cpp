/*
    Problem link->
        https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int start = 0, end = nums.size() - 1, n = nums.size();
        while(start < end){
            int mid = (start + end) >> 1;
            if(nums[mid] > nums[end]){
                start = mid + 1;
            }else if(nums[mid] < nums[end]) {
                end = mid;
            }else{
                end--;
            }
        }
        return nums[start];
    }
};