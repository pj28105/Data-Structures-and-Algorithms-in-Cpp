#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->  
        https://leetcode.com/problems/longest-palindromic-subsequence
    
    Tested on Leetcode
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty()){
            return 0;
        }
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j]){
                    if(i + 1 == j){
                        dp[i][j] = 2;
                    }else{
                       dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                }else{
                     dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};