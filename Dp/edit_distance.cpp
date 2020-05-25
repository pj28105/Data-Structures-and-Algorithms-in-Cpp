#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/edit-distance/
    
    Tested on Leetcde
*/

class Solution {
public:
    int minDistance(string w, string s) {
        vector<vector<int>>dp(2,vector<int>(s.length() + 1));
        dp[0][0] = 0;
        for(int i = 1; i <= s.length(); i++){
            dp[0][i] = 1 + dp[0][i - 1];
        }
        for(int i = 1; i <= w.length(); i++){
            int currRow = i & 1;
            for(int j = 0; j <= s.length(); j++){
               if(j == 0){
                   dp[currRow][j] = 1 + dp[currRow ^ 1][j];
               }
               else if(w[i - 1] != s[j - 1]){
                  dp[currRow][j] = 1 + min({ dp[currRow ^ 1][j],dp[currRow][j - 1],dp[currRow ^ 1][j - 1]});
               }
                else{
                   dp[currRow][j] = dp[currRow ^ 1][j - 1];
               }
            }
        }
        return dp[(w.length()) & 1][s.length()];
    }
};