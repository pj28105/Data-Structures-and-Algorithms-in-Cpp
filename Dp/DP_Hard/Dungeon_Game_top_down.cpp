/*
    Problem name->
        https://leetcode.com/problems/dungeon-game/
    
    Tested on Leetcode

    Note-> This problem can also be solved through binary search!
*/

class Solution {
public:
    int r,c;
    int solv(vector<vector<int>>&a,int i,int j,vector<vector<int>>&dp){
        if(i >= r || j >= c || i < 0 || j < 0){
            return 1e9;
        }
        if(i == r - 1 && j == c - 1){
            return a[i][j] > 0 ? 1 : (-1 * a[i][j] + 1);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        dp[i][j] = max(1,min(solv(a,i + 1,j,dp),solv(a,i,j + 1,dp)) - a[i][j]);
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& a) {
        if(a.empty() || a[0].empty()){
            return 1;
        }
        r = a.size(),c = a[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        return solv(a,0,0,dp);
    }
};