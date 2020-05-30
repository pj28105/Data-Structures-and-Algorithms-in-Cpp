#include<bits/stdc++.h>
using namespace std;
/*
    This is implementation of an atricle on GFG.
    Article Link->
        https://www.geeksforgeeks.org/find-distance-between-two-nodes-in-the-given-binary-tree-for-q-queries/?ref=leftbar-rightbar
    
    Tested Status False
*/

void dfs(int s,int cost,int parent,vector<vector<int>>&dp,vector<int>&lvl,vector<pair<int,int>>g[],vector<vector<int>>&dist,int maxL){
    if(s == parent){
        lvl[s] = 0;
    }else{
        lvl[s] = lvl[parent] + 1;
    }
    dp[s][0] = parent;
    dist[s][0] = cost;
    for(int i = 1; i <= maxL; i++){
        dp[s][i] = dp[dp[s][i - 1]][i - 1];
        dist[s][i] = dist[s][i - 1] + dist[dp[s][i - 1]][i - 1];
    }
    for(pair<int,int> v : g[s]){
        dfs(v.first,v.second,s,dp,lvl,g,dist,maxL);
    }
    return;
}

int find_dist(int a,int b,int maxL,vector<int>&lvl,vector<vector<int>>&dp,vector<vector<int>>&dist){
    if(lvl[a] < lvl[b]){
        swap(a,b);
    }
    int path_len = 0;
    int diff = lvl[a] - lvl[b];
    for(int i = maxL; i >= 0; i--){
        int currpow = 1ll << i;
        if(currpow <= diff){
            diff -= currpow;
            path_len += dist[a][i];
            a = dp[a][i];
        }
    }
    if(a == b){
        return path_len;
    }
    for(int i = maxL; i >= 0; i--){
        if(dp[b][i] != dp[a][i]){
            path_len += dist[b][i] + dist[a][i];
            b = dp[b][i];
            a = dp[a][i];
        }
    }
    path_len += dist[a][0] + dist[b][0];
    return path_len;
}

int main(void){
    freopen("in.txt","r",stdin);
    int v;
    cin >> v;
    vector<pair<int,int>>g[v];
    for(int i = 0; i < (v - 1); i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--,b--;
        g[a].push_back({b,w});
    }
    int maxL = ceil(log2(v));
    vector<int> lvl(v);
    vector<vector<int>>dist(v,vector<int>(maxL + 1));
    vector<vector<int>> dp(v,vector<int>(maxL + 1,-1));
    dfs(0,0,0,dp,lvl,g,dist,maxL);
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        a--,b--;
        cout << find_dist(a,b,maxL,lvl,dp,dist) << endl;
    }
}