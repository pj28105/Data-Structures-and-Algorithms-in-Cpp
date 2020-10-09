/*
    Problem link->
        https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1 || nums[0] <= nums.back()){
            return nums[0];
        }
        int s = 1,e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
            if(nums[0] <= nums[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return -1;
    }
};