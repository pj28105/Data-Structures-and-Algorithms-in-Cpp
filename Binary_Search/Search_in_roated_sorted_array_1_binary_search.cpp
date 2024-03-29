#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/search-in-rotated-sorted-array/
    
    Tested on Leetcode!

    Video Link->
        https://www.youtube.com/watch?v=oTfPJKGEHcc
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            return nums[0] == target ? 0 : -1;
        }
        int s = 0,e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] <= nums[e]){
                if(nums[mid] < target && nums[e] >= target){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }else if(nums[s] <= target && nums[mid] > target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return -1;
    }
};