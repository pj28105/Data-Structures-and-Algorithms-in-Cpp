#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/burst-balloons/

    Tested on Leetcode!
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        vector<long long>c_nums;
        c_nums.push_back(1);
        for(int i : nums){
            c_nums.push_back(i);
        }
        c_nums.push_back(1);
        vector<vector<long long>>dp(n + 1,vector<long long>(n + 1));
        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                if(i == j){
                    dp[i][j] = c_nums[i] * c_nums[i - 1] * c_nums[i + 1];
                }else{
                    dp[i][j] = dp[i + 1][j] + c_nums[i] * c_nums[i - 1] * c_nums[j + 1];
                    dp[i][j] = max(dp[i][j],dp[i][j - 1] + c_nums[j] * c_nums[j + 1] * c_nums[i - 1]);
                    for(int k = i + 1; k < j; k++){
                        dp[i][j] = max(dp[i][j],dp[i][k - 1] + dp[k + 1][j] + 
                                                c_nums[k] * c_nums[i - 1] * c_nums[j + 1]);
                    }
                }
            }
        }
        return dp[1][n];
    }
};