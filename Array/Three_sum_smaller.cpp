#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/3sum-smaller/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < int(nums.size()); i++){
           int req = target - nums[i],l = i + 1,r = nums.size() - 1;
           while(l < r){
               if((nums[l] + nums[r]) < req){
                   ans += (r - l);
                   l++;
               }else{
                   r--;
               }
           }
       }
       return ans;
    }
};