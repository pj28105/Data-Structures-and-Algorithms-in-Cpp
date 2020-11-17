/*
    Problem link->
        https://leetcode.com/explore/learn/card/binary-search/125/template-i/952/
    
    Tested on Leetcode!

    Checkout its more optimized solution in binary search folder!
*/
class Solution {
public:
    int searchPivot(vector<int>&nums){
        if(nums.size() == 2){
            return 1;
        }
        int s = 1,e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid - 1] > nums[mid]){
                return mid;
            }
            if(nums[0] <= nums[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return -1;
    }
    int bs(vector<int>nums,int s,int e,int target){
        while(s <= e){
            int mid = s + (e - s);
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }   
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            return nums[0] == target ? 0 : -1;
        }
        int pIndex = searchPivot(nums);
        if(pIndex == -1){
            return bs(nums,0,nums.size() - 1,target);     
        }
        if(nums[pIndex] <= target && target <= nums.back()){
            return bs(nums,pIndex,nums.size() - 1,target);
        }
        return bs(nums,0,pIndex - 1,target);
    }
};