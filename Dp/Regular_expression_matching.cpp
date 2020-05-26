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
        vector<vector<bool>> dp(p.length() + 1,vector<bool>(s.length() + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= p.length(); i++){
            for(int j = 0; j <= s.length(); j++){
                if(p[i - 1] == '*'){
                    dp[i][j] = dp[i - 2][j];
                    if(j > 0 && (p[i - 2] == s[j - 1] || p[i - 2] == '.')){
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                }else if(p[i - 1] == '.' && j > 0){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(j > 0 && s[j - 1] == p[i - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        // for(int i = 0; i <= p.length(); i++){
        //     for(int j = 0; j <= s.length(); j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[p.length()][s.length()];
    }
};