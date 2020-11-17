#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/longest-valid-parentheses/
    
    Tested on Leetcode!
*/
class Solution {
    public:
        int longestValidParentheses(string s) {
            vector <int> dp(s.length());
            int ans = 0;
            for (int i = 1; i < int(s.length()); i++) {
                if (s[i] == ')' && s[i - 1] == '(') {
                    if (i >= 2) {
                        dp[i] = dp[i - 2];
                    }
                    dp[i] += 2;
                } else if (s[i] == ')') {
                    if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if ((i - dp[i - 1] - 2) >= 0) {
                            dp[i] += dp[i - dp[i - 1] - 2];
                        }
                    }
                }
                ans = max(ans, dp[i]);
            }
            return ans;
        }
};