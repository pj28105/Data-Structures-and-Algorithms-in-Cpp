#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/regular-expression-matching/
    
    Tested on Leetcode!
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        bool dp[n + 1][m + 1];
        memset(dp,false,sizeof(dp));
        dp[0][0] = 1; 
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(j == 0){
                    if(p[i - 1] == '*'){
                        dp[i][j] = dp[i - 2][j];
                    }
                }else{
                    if(p[i - 1] != '.' && p[i - 1] != '*'){
                        dp[i][j] = p[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : false;
                    }else if(p[i - 1] == '.'){
                        dp[i][j] = dp[i - 1][j - 1];
                    }else{
                        dp[i][j] = dp[i - 2][j];
                        if(p[i - 2] == '.' || p[i - 2] == s[j - 1]){
                            dp[i][j] = dp[i][j] || dp[i][j - 1];
                        }
                    }
                }
            }
        }
        return dp[n][m];
    }
};