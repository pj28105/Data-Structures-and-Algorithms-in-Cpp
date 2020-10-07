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
        int s = 1,e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(mid != 0 && nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
            else if(nums[mid] < nums[0]){
                e = mid - 1;
            }else if(nums[mid] > nums[0]){
                s = mid + 1;
            }else if(nums[0] != nums[e]){
                s = mid + 1;
            }else{
                e--;
            }
        }
        return nums[0];
    }
};