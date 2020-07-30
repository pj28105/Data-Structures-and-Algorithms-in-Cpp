#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/3085/

    Tested on Leetcode!
*/
class Solution {
public:
     long long crossum(vector<int>&nums,int l,int mid,int r){
         long long left_max_suffix = INT_MIN;
         long long sum = 0;
         for(int i = mid; i >= 0; i--){
             sum += nums[i];
             left_max_suffix = max(left_max_suffix,sum);
         }
         sum = 0;
         long long right_max_prefix = INT_MIN;
         for(int i = mid + 1; i <= r; i++){
             sum += nums[i];
             right_max_prefix = max(right_max_prefix,sum);
         }
         return left_max_suffix + right_max_prefix;
     }
     long long solv(int st,int se,vector<int>& nums){
        if(st == se){
            return nums[st];
        }
        int mid = (st + se) >> 1;
        long long lsum = solv(st,mid,nums);
        long long rsum = solv(mid + 1,se,nums);
        long long ans = max({crossum(nums,st,mid,se),lsum,rsum});
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        return solv(0,nums.size() - 1,nums);
    }
};