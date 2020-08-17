#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://leetcode.com/problems/optimize-water-distribution-in-a-village/
    
    Tested on Leetcode!
*/
class DSU{
public:
    vector<int>par,rank;
    DSU(int n){
        par.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }
        par[x] = find(par[x]);
        return par[x];
    }
    void union_them(int par_x,int par_y){
        if(par_x == par_y){
            return;
        }
        if(rank[par_x] > rank[par_y]){
            par[par_y] = par_x;
            return;
        }
        if(rank[par_x] < rank[par_y]){
            par[par_x] = par_y;
            return;
        }
        par[par_y] = par_x;
        rank[par_x]++;
        return;
    }
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        DSU dsu(n + 1);
        for(int i = 0; i < wells.size(); i++){
            pipes.push_back({0,i + 1,wells[i]});
        }
        sort(pipes.begin(),pipes.end(),[](auto &x,auto &y)->bool{
            return x[2] <= y[2];     
        });
        int edg_cnt = 0,ans = 0;
        for(auto &i : pipes){
            if(edg_cnt == n){
                break;
            }
            int par_x = dsu.find(i[0]);
            int par_y = dsu.find(i[1]);
            if(par_x != par_y){
                ans += i[2];
                edg_cnt++;
                dsu.union_them(par_x,par_y);
            }
        }
        return ans;
    }
};