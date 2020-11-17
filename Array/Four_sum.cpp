#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/4sum/
    
    Tested on Leetcode!
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i < int(nums.size()); i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                for(int j = i + 1; j < int(nums.size()); j++){
                    if(j == i + 1 || nums[j] != nums[j - 1]){
                        int req = target - (nums[i] + nums[j]);
                        int l = j + 1,r = nums.size() - 1;
                        while(l < r){
                            if((nums[l] + nums[r]) == req){
                                ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                                l++,r--;
                                while(l < r && nums[l] == nums[l - 1]){
                                    l++;
                                }
                                while(l < r && nums[r] == nums[r + 1]){
                                    r--;
                                }
                            }else if((nums[l] + nums[r]) < req){
                                l++;
                            }else{
                                r--;
                            }
                        }
                    }
                }   
            }
        }
        return ans;
    }
};