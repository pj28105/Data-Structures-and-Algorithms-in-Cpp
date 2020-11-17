#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/k-closest-points-to-origin/

    Note->
        This problem can be solved by using quick_select (quick_sort) in  o(N) at average
        and o(N^2) in worst case!
        
    Tested on Leetcode
*/
class Solution {
public:
    double find_dist(int x,int y){
        return sqrt((x * x) + (double)(y * y)); 
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double>q;
        for(int i = 0; i < points.size(); i++){
            q.push(find_dist(points[i][0],points[i][1]));
            if(q.size() > k){
                q.pop();
            }
        }
        vector<vector<int>>ans;
        for(int i = 0; i < points.size(); i++){
            double currdist = find_dist(points[i][0],points[i][1]);
            if(currdist <= q.top()){
                ans.push_back(points[i]);
            }
        }
        return ans;
    }
};