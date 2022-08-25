/*
    Problem link->
        https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
    
    Tested on Leetcode!
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 1){
            return (nums[0] == target ? true : false);
        }
        int start = 0,  end = nums.size() - 1;
        while(start <= end){
            int mid = (start + end) >> 1;
            if (nums[mid] == target){
                return 1;
            }
            if(nums[mid] == nums[start] && nums[start] == nums[end]) {
                start++,end--;
            } else if(nums[start] <= nums[mid]){
                if(nums[start] <= target && nums[mid] >= target){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{
                if(nums[mid] <= target && nums[end] >= target){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};