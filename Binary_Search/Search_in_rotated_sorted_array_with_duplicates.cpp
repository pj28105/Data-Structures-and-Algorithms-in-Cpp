/*
    Problem link->
        https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
    
    Tested on Leetcode!
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0] == target;
        }
        int s = 0,e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                return 1;
            }
            if(nums[s] < nums[mid]){
                if(nums[s] <= target && nums[mid] > target){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }else if(nums[e] > nums[mid]){
                if(nums[mid] < target && nums[e] >= target){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }else if(nums[s] == nums[mid]){
                s++;
            }else{
                e--;
            }
        }
        return false;
    }
};