/*
    Problem link->
        https://leetcode.com/problems/palindrome-partitioning-ii/
    
    Tested on Leetcode!
*/
class Solution {
public:
    int dp[100000];
    bool checkPalindrome(string& s){
        int len = s.length();
        for(int i = 0,j = len - 1; i < len/2; i++,j--){
            if(s[i] != s[j])
                return false;
        } 
        return true;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int len = s.length();
        vector<vector<bool>> pal(len,vector<bool>(len));
        for(int i = 0; i < len; i++){
            string currString = "";
            for(int j = i; j < len; j++){
                currString  += s[j];
                pal[i][j] = checkPalindrome(currString);
            }
        }
        dp[len - 1] = 1;
        for(int i = len - 2; i >= 0; i--){
            dp[i] = INT_MAX;
            for(int j = i; j < len; j++){
                if(pal[i][j]){
                    int currAns = 1;
                    if((j + 1) < len){
                        currAns += dp[j + 1];
                    }
                    dp[i] = min(dp[i],currAns);
                }    
            }
        }
        return dp[0] - 1;
    }
};