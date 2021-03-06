/*
    Problem link->
        https://leetcode.com/problems/android-unlock-patterns/
    
    Checkout its dp solution!
    Tested on Leetcode!
*/
class Solution {
public:
    int cnt = 0;
    void solv(int currlen,int currpos,int m,int n,unordered_set<int>&vis,vector<vector<int>>&valid){
        if(currlen >= m){
            cnt++;
            if(currlen == n){
                return;
            }
        }
        for(int i = 1; i <= 9; i++){
            if(!vis.count(i) && (valid[currpos][i] == 0 || vis.count(valid[currpos][i]))){
                vis.insert(i);
                solv(currlen + 1,i,m,n,vis,valid);
                vis.erase(i);
            }
        }
        return;
    }
    int numberOfPatterns(int m, int n) {
        vector<vector<int>>valid(10,vector<int>(10));
        valid[1][3] = valid[3][1] = 2;
        valid[1][7] = valid[7][1] = 4;
        valid[7][9] = valid[9][7] = 8;
        valid[3][9] = valid[9][3] = 6;
        valid[1][9] = valid[9][1] = valid[3][7] = valid[7][3] = 
        valid[4][6] = valid[6][4] = valid[2][8] = valid[8][2] = 5;
        int ans = 0;
        unordered_set<int>vis;
        int st[3] = {1,2,5};
        for(int i = 0; i < 3; i++){
            vis.insert(st[i]);
            cnt = 0;
            solv(1,st[i],m,n,vis,valid);
            if(i < 2){
                cnt  = 4 * cnt;
            }
            ans += cnt;
            vis.erase(st[i]);
        }
        return ans;
    }
};