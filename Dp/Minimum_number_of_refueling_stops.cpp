/*
    Problem link ->  https://leetcode.com/problems/minimum-number-of-refueling-stops

    Tested on Leetcode
    
    Notes -: 
        1) Do checkout its Greedy approach with heap O(NLogn) which is more intuitive
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = startFuel;
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(dp[j] >= stations[i][0]){
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }else{
                    break;
                }
            }
        }
        for(int i = 0; i <= n; i++){
            if(dp[i] >= target){
                return i;
            }
        }
        return -1;
    }
};