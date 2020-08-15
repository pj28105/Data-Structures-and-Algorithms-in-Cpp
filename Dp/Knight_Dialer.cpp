#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/knight-dialer/
    
    Google's Favourite DP question!
    Tested on Leetcode!
*/
const int mod = 1e9 + 7; 
class Solution {
public:
    vector<vector<int>>key_map;
    int knightDialer(int n) {
        if(n == 1){
            return 10;
        }
        if(key_map.empty()){
            key_map.resize(10);
            key_map[0] = {4,6};
            key_map[1] = {8,6};
            key_map[2] = {7,9};
            key_map[3] = {8,4};
            key_map[4] = {0,3,9};
            key_map[5] = {};
            key_map[6] = {1,7,0};
            key_map[7] = {2,6};
            key_map[8] = {1,3};
            key_map[9] = {2,4};
        }
        vector<vector<int>>dp(2,vector<int>(10,1));
        dp[1][5] = 0;
        int currRow = 1;
        for(int i = 2;  i < n; i++){
            currRow = (i & 1);
            for(int j = 0; j <= 9; j++){
                dp[currRow][j] = 0;
                for(int k = 0; k < key_map[j].size(); k++){
                    dp[currRow][j] = (dp[currRow][j] + (long long)dp[currRow ^ 1][key_map[j][k]]) % mod;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= 9; i++){
            if(i == 4 || i == 6){
                ans = (ans + ((3 * (long long)dp[currRow][i]) % mod)) % mod;
            }else{
                ans = (ans + ((2 * (long long)dp[currRow][i]) % mod)) % mod;
            }
        }
        return ans;
    }
};