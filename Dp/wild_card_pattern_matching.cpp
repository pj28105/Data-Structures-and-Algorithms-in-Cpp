#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/wildcard-matching/

    Tested on Leetcode!
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int dp[p.length() + 1][s.length() + 1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= p.length(); i++){
            for(int j = 0; j <= s.length(); j++){
                if(p[i - 1] == '*'){
                    dp[i][j] = dp[i - 1][j];
                    if(j > 0){
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                }
                else if(j > 0 && p[i - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(j > 0 && p[i - 1] == s[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[p.length()][s.length()];
    }
};