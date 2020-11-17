/*
    Problem link->
        https://leetcode.com/problems/android-unlock-patterns/submissions/
    
    Checkout its backtracking solution!
    Tested on Leetcode!
*/
class Solution {
public:
    int solv(int mask,int currlen,int currpos,int m,int n,vector<vector<int>>&valid,vector<vector<int>>&dp){
        if(currlen == n){
            return 0;
        }
        if(dp[mask][currpos] != -1){
            return dp[mask][currpos];
        }
        int ans = 0;
        for(int i = 1; i <= 9; i++){
            int ch_mk = 1 << (i - 1);
            if((mask & ch_mk) == 0){
                int must_visit = valid[currpos][i];
                if(must_visit == 0 || mask & (1 << (must_visit - 1))){
                    if((currlen + 1) >= m){
                        ans += 1 + solv(mask | (1 << (i - 1)),currlen + 1,i,m,n,valid,dp);    
                    }else{
                        ans += solv(mask | (1 << (i - 1)),currlen + 1,i,m,n,valid,dp);
                    }                    
                }
            }
        }
        dp[mask][currpos] = ans;
        return ans;
    }
    int numberOfPatterns(int m, int n) {
        vector<vector<int>>dp(1 << 9,vector<int>(10,-1));
        vector<vector<int>>valid(10,vector<int>(10));
        valid[1][3] = valid[3][1] = 2;
        valid[1][7] = valid[7][1] = 4;
        valid[7][9] = valid[9][7] = 8;
        valid[3][9] = valid[9][3] = 6;
        valid[1][9] = valid[9][1] = valid[3][7] = valid[7][3] = 
        valid[4][6] = valid[6][4] = valid[2][8] = valid[8][2] = 5;
        int ans = 0;
        int mask = 0;
        for(int i = 1; i <= 9; i++){
            if(m == 1)
                ans += 1 + solv(1 << (i - 1),1,i,m,n,valid,dp);    
            else
                ans += solv(1 << (i - 1),1,i,m,n,valid,dp);
        }
        return ans;
    }
};