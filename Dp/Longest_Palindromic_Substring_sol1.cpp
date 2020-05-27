#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string2235/1/?track=amazon-dynamic-programming&batchId=192
    
    Checkout its another solution which is more optimized in space complexity in DP folder!
    Tested on GFG and Leetcode!
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int st = 0,en = -1;
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n));
        int maxlen = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 1;
                }else if(s[i] == s[j]){
                    if(i + 1 == j){
                        dp[i][j] = 2;
                    }else if(dp[i + 1][j - 1] == (j - i - 1)){
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                }else{
                    dp[i][j] = 0;
                }
                if(maxlen <= dp[i][j]){
                    st = i;
                    en = j;
                    maxlen = dp[i][j];
                }
            }
        }
        char str [maxlen + 1];
        str[maxlen] = '\0';
        int i = 0,j = maxlen - 1;
        while((st <= en && maxlen > 0)){
            str[i] = s[st];
            str[j] = s[en];
            en--;
            st++;
            i++;
            j--;
            maxlen -= 2;
        }
        string ans(str);
        return ans;
    }
};