#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/explore/interview/card/google/59/array-and-strings/3061/

    Tested on Leetcode!
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        vector<pair<double,int>>a;
        for(int i = 0; i < q.size(); i++){
            a.push_back({w[i]/(double)q[i],q[i]});
        }
        sort(a.begin(),a.end());
        double ans = 0,quality_sum = 0;
        priority_queue<int>pq;
        for(int i = 0; i < k; i++){
            quality_sum += a[i].second;
            pq.push(a[i].second);
        }
        ans = a[k - 1].first * quality_sum;
        for(int i = k; i < a.size(); i++){
            if(pq.top() > a[i].second){
                quality_sum -= pq.top();
                pq.pop();
                pq.push(a[i].second);
                quality_sum += a[i].second;
            }
            ans = min(ans,a[i].first * quality_sum);
        }
        return ans;
    }
};