#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/3sum/
    
    Tested on Leetcode!
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i <= int(nums.size() - 3); i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                int l = i + 1,r = nums.size() - 1,req = -nums[i];
                while(l < r){
                    if((nums[l] + nums[r] == req)){
                        ans.push_back({nums[i],nums[l],nums[r]});
                        l++,r--;
                        while(l < r && nums[l] == nums[l - 1]){
                            l++;
                        }
                        /*You can omit this loop!*/
                        while(l < r && nums[r] == nums[r + 1]){
                            r--;
                        }
                    }else if(req > (nums[l] + nums[r])){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};