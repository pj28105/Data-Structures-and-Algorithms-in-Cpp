/*
    Problem link->
        https://leetcode.com/problems/missing-element-in-sorted-array/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return k + nums[0];
        }
        int s = 0,e = nums.size() - 1,ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if((nums[mid] - nums[0] - mid) >= k){
                e = mid - 1;
            }else{
                ans = mid;
                s = mid + 1;
            }
        }
        return nums[ans] + k - (nums[ans] - nums[0] - ans);
    }
};