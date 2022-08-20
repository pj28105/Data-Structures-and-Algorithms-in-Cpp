/*
    Problem link ->  https://leetcode.com/problems/minimum-number-of-refueling-stops

    Tested on Leetcode
    
    Notes -: 
        1) Do checkout its Dynamic programming approach with O(N^2)
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int stops = 0;
        priority_queue<int> q;
        int fuel = startFuel, prevDest = 0;
        for(int i = 0; i < n; i++){
            fuel = fuel - (stations[i][0] - prevDest);
            while(!q.empty() && fuel < 0){
                fuel += q.top();
                q.pop();
                stops++;
            }
            if(fuel < 0){
                return -1;
            }
            q.push(stations[i][1]);
            prevDest = stations[i][0];
        }
        fuel = fuel - (target - prevDest);
        while(!q.empty() && fuel < 0){
            fuel += q.top();
            q.pop();
            stops++;
        }
        if(fuel < 0){
            return -1;
        }
        return stops;
    }
};