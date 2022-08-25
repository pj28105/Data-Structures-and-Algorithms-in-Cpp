/*
    Problem link->
        https://leetcode.com/problems/find-peak-element/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int n = nums.size(), start = 0, end = n - 1;
        while(start <= end){
            int mid = (start + end) >> 1;
            if(mid == 0) {
                if(nums[1] < nums[0]) {
                    return 0;
                }else{
                    start = mid + 1;
                }
            }else if(mid == n - 1) {
                if(nums[n - 2] < nums[n - 1]){
                    return n - 1;
                }
                end = mid - 1;
            }else if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]){
                return mid;
            }else{
                if(nums[mid] > nums[mid - 1]) {
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};