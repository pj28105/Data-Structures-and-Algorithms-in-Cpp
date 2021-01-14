/*
    This Problem is based on backtracking with pruning!
    Problem link->
        https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
    
    Tested on Leetcode!
*/
typedef long long ll;
class Solution {
public:
    ll ansMax = INT64_MAX;
    void solv(int n,int k,int i,vector<int>&jobs,vector<ll>&workers,ll currMax){
        if(currMax > ansMax){
            return;
        }
        if(i == n){
            ansMax = currMax;
            return;
        }
        unordered_set<ll>vis;
        for(int j = 0; j < k; j++){
            if(!vis.count(workers[j])){
                vis.insert(workers[j]);
                workers[j] += jobs[i];
                solv(n,k,i + 1,jobs,workers,max(currMax,workers[j]));
                workers[j] -= jobs[i];   
            }
        }
        return;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        ansMax = INT64_MAX;
        vector<ll>workers(k,0);
        solv(jobs.size(),k,0,jobs,workers,0);
        return ansMax;
    }
};