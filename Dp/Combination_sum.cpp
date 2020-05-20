#include<bits/stdc++.h>
using namespace std;

/*
    Problem link->
        https://leetcode.com/problems/combination-sum/
    
    Note-> This problem is same as coin change!
    Tested on Leetcode
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int sum) {
        vector<vector<int>> dp[sum + 1];
        for(int i = 0; i < a.size(); i++){
          for(int j = a[i]; j <= sum; j++){
                if(j == a[i]){
                    dp[j].push_back(vector<int>(1,a[i]));
                }else if(!dp[j - a[i]].empty()){
                    for(auto k : dp[j - a[i]]){
                        k.push_back(a[i]);
                        dp[j].push_back(k);
                    }
                }
             }
          }
        return dp[sum];
    }
};