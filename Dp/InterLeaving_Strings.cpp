#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/interleaving-string/

    Tested on Leetcode!
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.length() + s2.length()) != s3.length()){
            return 0;
        }
        int n = s1.length(),m = s2.length();
        vector<vector<bool>>dp(n + 1,vector<bool>(m + 1,0));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == j && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                int in = i + j - 1;
                if(i != 0 && s3[in] == s1[i - 1]){
                    dp[i][j] = 1;
                    if(i > 0){
                        dp[i][j] = dp[i - 1][j];
                    }
                }
                if(j != 0 && s3[in] == s2[j - 1]){
                    if(j > 0){
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }else{
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[n][m];
    }
};