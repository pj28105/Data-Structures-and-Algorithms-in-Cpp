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
    int dp[1000][1000];
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }
        int n = s.length();
        memset(dp,0,sizeof(dp));
        int maxLen = 0,st = -1,en = -1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 1;
                }else if(s[i] == s[j] && dp[i + 1][j - 1] == (j - i - 1)){
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    st = i;
                    en = j;
                }
            }
        }
        return s.substr(st,en - st + 1);
    }
};